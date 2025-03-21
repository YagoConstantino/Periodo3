/*Criação de uma Lista de adjacencias para representar um Grafo*/

typedef struct grafo
{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int **arestas;
    float **pesos;
    int *grau;
}Grafo;

Grafo* criaGrafo(int n_vertices,int grauMax,int ponderado);
void liberaGrafo(Grafo *gr);
int insereAresta(Grafo *gr,int orig,int dest,int eh_Digrafo,float peso);
int removeAresta(Grafo* gr,int orig,int dest,int eh_Digrafo);
void printGrafo(Grafo* gr);

void buscaProfundidadeGrafo(Grafo* gr,int ini,int *visitado);
void auxBuscaProfundidade(Grafo* gr,int ini,int *visitado,int cont);

void buscaLarguraGrafo(Grafo* gr,int ini,int* visitado);

void menorCaminhoGrafo(Grafo* gr,int ini,int *ant,float *distancia);
int procuraMenorDistancia(float *dist,int *visitado,int NV);