#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

// Função para imprimir o vetor de visitados
void imprimeVisitados(int *visitado, int num_vertices) 
{
    printf("\nOrdem de visita:\n");
    for (int i = 0; i < num_vertices; i++) 
    {
        printf("Vértice %d: %dº a ser visitado\n", i, visitado[i]);
    }
}

int main() 
{
    int num_vertices = 8;
    int grau_max = 5;
    int eh_ponderado = 1;  // 1 para grafo ponderado, 0 para não ponderado

    // Cria o grafo
    Grafo *gr = criaGrafo(num_vertices, grau_max, eh_ponderado);

    // Insere arestas (o parâmetro "eh_Digrafo" = 0 indica que o grafo não é direcionado)
    insereAresta(gr, 0, 1, 0, 2.5);
    insereAresta(gr, 0, 4, 0, 3.7);
    insereAresta(gr, 1, 2, 0, 1.2);
    insereAresta(gr, 1, 3, 0, 4.0);
    insereAresta(gr, 2, 3, 0, 5.5);
    insereAresta(gr, 3, 4, 0, 6.6);
    insereAresta(gr, 4, 5, 0, 2.1);
    insereAresta(gr, 5, 6, 0, 3.3);
    insereAresta(gr, 6, 7, 0, 4.4);
    insereAresta(gr, 7, 0, 0, 5.5);

    // Imprime o grafo após as inserções
    printf("Grafo após inserção de arestas:\n");
    printGrafo(gr);

    // Testa a busca em profundidade a partir do vértice 0
    int visitado[num_vertices];
    buscaProfundidadeGrafo(gr, 0, visitado);

    // Imprime a ordem de visita da busca em profundidade
    printf("\nResultado da busca em profundidade:\n");
    imprimeVisitados(visitado, num_vertices);

    // Testa a busca em largura a partir do vértice 0
    buscaLarguraGrafo(gr, 0, visitado);

    // Imprime a ordem de visita da busca em largura
    printf("\nResultado da busca em largura:\n");
    imprimeVisitados(visitado, num_vertices);

    // Remove a aresta entre 1 e 3
    removeAresta(gr, 1, 3, 0);

    // Imprime o grafo após a remoção
    printf("\nGrafo após remoção da aresta entre 1 e 3:\n");
    printGrafo(gr);

    // Testa a busca em profundidade novamente
    buscaProfundidadeGrafo(gr, 0, visitado);
    printf("\nResultado da busca em profundidade após remoção:\n");
    imprimeVisitados(visitado, num_vertices);

    // Libera a memória alocada para o grafo
    liberaGrafo(gr);

    return 0;
}
