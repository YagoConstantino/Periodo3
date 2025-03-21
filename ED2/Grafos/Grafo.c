#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

Grafo *criaGrafo(int n_vertices, int grauMax, int ponderado)
{
    Grafo* gr = (Grafo*)malloc(sizeof(Grafo));

    if(gr!=NULL)
    {
        int i;
        gr->nro_vertices = n_vertices;
        gr->grau_max = grauMax;
        gr->eh_ponderado =  (ponderado != 0) ? 1 : 0;
        gr->grau = (int*)calloc(n_vertices,sizeof(int));
        gr->arestas = (int**)malloc(n_vertices* sizeof(int*));

        for(i=0;i<n_vertices;i++)
            gr->arestas[i] = (int*)malloc(grauMax*sizeof(int));
        
        if(gr->eh_ponderado)
        {
            int j;
            gr->pesos = (float**)malloc(n_vertices*sizeof(float*));
            for(j=0;j<n_vertices;j++)
                gr->pesos[j] = (float*)malloc(grauMax*sizeof(float));
        }
        
    }
    return gr;
}

void liberaGrafo(Grafo *gr)
{
    if(gr != NULL)
    {
        int i;
        for(i=0;i<gr->nro_vertices;i++)
            free(gr->arestas[i]);
        free(gr->arestas);
        
        if(gr->eh_ponderado)
        {
            for(i=0;i<gr->nro_vertices;i++)
                free(gr->pesos[i]);
            free(gr->pesos);    
        }
        free(gr->grau);
        free(gr);
    }
}

int insereAresta(Grafo *gr, int orig, int dest, int eh_Digrafo, float peso)
{
    if(gr == NULL) return 0;
    
    if(orig < 0 || orig >= gr->nro_vertices ) return 0;

    if(dest < 0 || dest >= gr->nro_vertices ) return 0;

    if(gr->grau[orig] >= gr->grau_max) return 0;

    gr->arestas[orig][gr->grau[orig]] = dest;

    if(gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;
       
    gr->grau[orig]++;
    
    if(eh_Digrafo == 0)
        insereAresta(gr,dest,orig,1,peso);
    return 1;    
}

int removeAresta(Grafo *gr, int orig, int dest, int eh_Digrafo)
{
    if(gr == NULL) return 0;

    if(orig < 0 || orig >= gr->nro_vertices ) return 0;

    if(dest < 0 || dest >= gr->nro_vertices ) return 0;

    int i = 0;    
    while( i < gr->grau[orig] && gr->arestas[orig][i] != dest)
        i++;

    if(i == gr->grau[orig]) return 0;
    
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];

    if(gr->eh_ponderado)
        gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];

    if(eh_Digrafo == 0)
        removeAresta(gr,dest,orig,1);
     
    return 1;    
}

void printGrafo(Grafo *gr) 
{
    if (gr == NULL) 
    {
        printf("Grafo vazio.\n");
        return;
    }
    
    printf("Grafo:\n");
    printf("Número de vértices: %d\n", gr->nro_vertices);
    for (int i = 0; i < gr->nro_vertices; i++) 
    {
        printf("Vértice %d: ", i);
        for (int j = 0; j < gr->grau[i]; j++) 
        {
            if (gr->eh_ponderado)
                printf("(%d, peso: %.2f) ", gr->arestas[i][j], gr->pesos[i][j]);
            else
                printf("%d ", gr->arestas[i][j]);
        }
        printf("\n");
    }
}

/*
Busca em profundidade
    Partindo de um vertice inicial,ela explora ao maximo possivel cada um dos Ramos antes de voltar
    indo até o vertice mais distante antes de explorar os outros caminhos proximos que partem do 
    vertice inicial
    -Encontrar componentes fortemente conectados
    -Ordenação topologica do grafo
    -Resolver Quebra-cabeças
    A ordem da busca (caminho) que será a resposta é armazenado no vetor visitado
    Usa uma função auxiliar(assim como o merge e particionar),a buscaProfundidadeGrafo so inicializa
    o vetor e chama a auxiliar
*/

void buscaProfundidadeGrafo(Grafo *gr, int ini, int *visitado)
{
    int i,cont = 1;
    for(i=0;i<gr->nro_vertices;i++)
        visitado[i] = 0;
    auxBuscaProfundidade(gr,ini,visitado,cont);
}
/*
    Função que realiza a busca
    - seta o vertice inicial com o primeiro visitado(cont = 1)
    -percorre todas as arestas do vertice [ini](o loop usando i)
    -se nao foi visitado chama a busca para esse vertice
    -vai ir profundamente no primero vertice apontado pela primeira aresta,depois profundamente
    para a segunda aresta(se exister ) do inicial e assim por diante,


*/
void auxBuscaProfundidade(Grafo *gr, int ini, int *visitado, int cont)
{
    int i;
    visitado[ini] = cont;
    for(i=0;i<gr->grau[ini];i++)
    {
        if(!visitado[gr->arestas[ini][i]])
            auxBuscaProfundidade(gr,gr->arestas[ini][i],visitado,cont+1);
    }

}

/*
Busca em largura
    -Partindo do vetice inicial ela explora todos os vertices vizinhos antes de se aprofundar 
    isto é explora todos os proximos do inicial antes e buscar os mais distantes,repete esse processo
    visitando os vertices ainda nao explorados
    -Achar componentes conectados
    -Achar todos os vertices conectados a um componente
    -achar o menor caminho entre dois vertices
*/

/*
    Execução:
        -Usamos uma fila auxiliar, como um vetor de int e dois inteiros para sinalizar o 
        -Inicio da Fila(IF) e o Fim da Fila(FF), o Numero de vertices(NV) é usado para sabermos
        o tamanho da Fila
        -zeramos o vetor de visitados 
        -inserimos o vertice inicial na fila
        -colocamos o inicial como o primeiro visitado(cont = 1) no vetor de visitados
*/
void buscaLarguraGrafo(Grafo *gr, int ini, int *visitado)
{
    int i,vert,NV,cont = 1,*fila,FF = 0,IF = 0;
    for(i=0;i<gr->nro_vertices;i++)
        visitado[i] = 0;

    NV = gr->nro_vertices;
    fila = (int*)malloc(sizeof(int)*NV);
    FF++;
    fila[FF] = ini;
    visitado[ini] = cont;
    
    //Enquanto nao terminamos a fila
    while(IF!=FF)
    {
        //Pegamos o primeiro da Fila
        IF = (IF+1) % NV;
        vert = fila[IF];
        cont++;

        //Visitamos os vizinhos ainda nao visitados e colocamos na fila
        for(i=0;i<gr->arestas[vert][i];i++)
        {
            if(!visitado[gr->arestas[vert][i]])
            {
                FF = (FF+1) % NV;
                fila[FF] = gr->arestas[vert][i];
                //Colocamos esse vizinho que colocamos na fila como visitado no vetor de visitados;
                visitado[gr->arestas[vert][i]] = cont;
            }   
        }
    }
    //desalocamos a fila
    free(fila);
}



/*
Busca pelo menor caminho em um grafo
    Partindo de um vertice inicial calcula a menor distancia desse vertice a todos os demais
    (desde que exista um caminho entre eles)
    -Algoritmo de Dijkstra
    -Utiliza uma função auxiliar chamada procuraMenorDistancia
*/

int procuraMenorDistancia(float *dist, int *visitado, int NV)
{
    int i,menor = -1,primeiro = 1;
    
    for(i=0;i<NV;i++)
    {
        if(dist[i]>=0 && visitado[i]==0)
        {
            if(primeiro)
            {
                menor = i;
                primeiro = 0;
            }
            else
                if(dist[menor]>dist[i])
                    menor = i;
        }
    }
    return menor;
}

void menorCaminhoGrafo(Grafo *gr, int ini, int *ant, float *distancia)
{
    int i,cont,NV,ind,*visitado,u;

    //Crio o vetor de visitado e inicializo os vetores distancia e ant
    cont = NV = gr->nro_vertices;

    visitado =(int*)malloc(sizeof(int)*NV);

    for(i=0;i<NV;i++)
    {
        ant[i] = -1;
        distancia[i] = -1;
        visitado[i] = 0;
    }

    distancia[ini] = 0;

    while(cont > 0)
    {
        u = procuraMenorDistancia(distancia,visitado,NV);
        if(u == -1)
            break;;
        visitado[u] = 1;
        cont--;
        
        //Para cada vertice devo visitar todos os seus vizinhos(busca em largura)

        for(i=0;i<gr->grau[i];i++)
        {
            //percorro todos os i vizinhos do vertice u
            ind = gr->arestas[u][i];

            if(distancia[ind]<0) //ou seja = -1 e portanto nao calculada a distancia ainda
            {
                distancia[ind] = distancia[u] +1;
                /*
                ou peso da aresta
                dist[ind] = dist[u]+gr->peos[u][i]
                */
               ant[ind] = u;
            }
            else
            {
                if(distancia[ind] > distancia[u]+1)
                {
                    distancia[ind] = distancia[u]+1;
                    /*
                    ou peso da aresta
                    dist[ind] = dist[u]+gr->peos[u][i]
                    */
                   ant[ind] = u;
                }
            }
        }
    }

    free(visitado);
}


