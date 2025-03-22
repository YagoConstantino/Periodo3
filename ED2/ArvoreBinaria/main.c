#include "Arvore.h"

int main() {
    // Cria uma árvore vazia
    Tree arvore = NULL;

    printf("========== TESTE DE INSERÇÃO ==========\n");
    // Insere valores na árvore (iterativo)
    iterativeInsertBST(&arvore, 50); // Raiz
    iterativeInsertBST(&arvore, 30);
    iterativeInsertBST(&arvore, 70);
    iterativeInsertBST(&arvore, 20);
    iterativeInsertBST(&arvore, 40);
    iterativeInsertBST(&arvore, 60);
    iterativeInsertBST(&arvore, 80);
    iterativeInsertBST(&arvore, 70); // Teste de duplicata

    printf("\n========== TRAVESSIAS ==========\n");
    printf("Em-ordem (crescente): ");
    inOrder(arvore); // Saída esperada: 20 30 40 50 60 70 80

    printf("\nEm-ordem reversa (decrescente): ");
    inDesorder(arvore); // Saída esperada: 80 70 60 50 40 30 20

    printf("\nPré-ordem: ");
    preOrder(arvore); // Saída esperada: 50 30 20 40 70 60 80

    printf("\nPós-ordem: ");
    posOrder(arvore); // Saída esperada: 20 40 30 60 80 70 50

    printf("\n\n========== BUSCA ==========\n");
    // Busca recursiva
    Node *buscaRec = TreeSerch(arvore, 40);
    printf("Busca recursiva por 40: %s\n", buscaRec ? "Encontrado" : "Não encontrado");

    // Busca iterativa
    Node *buscaIt = TreeSerchIterative(arvore, 90);
    printf("Busca iterativa por 90: %s\n", buscaIt ? "Encontrado" : "Não encontrado");

    printf("\n========== ESTATÍSTICAS ==========\n");
    printf("Total de nós: %d\n", contarValores(arvore)); // Saída: 7
    printf("Soma dos valores: %d\n", valorTotalArvore(arvore)); // Saída: 350

    printf("\n========== MÍNIMO E MÁXIMO ==========\n");
    // Versões iterativas (valor)
    printf("Mínimo (iterativo): %d\n", iterativeTreeMinimun(arvore)); // 20
    printf("Máximo (iterativo): %d\n", iterativeTreeMaximun(arvore)); // 80
    // Testa as funções
    printf("Mínimo: %d\n", recursiveTreeMinimun(arvore)); // Saída: 20
    printf("Máximo: %d\n", recursiveTreeMaximun(arvore)); // Saída: 70

    // Versões recursivas (nó)
    Node *minNo = NODErecursiveTreeMinimun(arvore);
    printf("Mínimo (nó recursivo): %d\n", minNo ? minNo->info : -1); // 20

    Node *maxNo = NODEiterativeTreeMaximun(arvore);
    printf("Máximo (nó iterativo): %d\n", maxNo ? maxNo->info : -1); // 80

    printf("\n========== RELACIONAMENTOS ==========\n");
    Node *no40 = TreeSerch(arvore, 40);
    printf("Pai de 40: %d\n", getFather(no40)->info); // 30
    printf("Filho esquerdo de 30: %d\n", getLeft(getFather(no40))->info); // 20
    printf("É filho esquerdo? %d\n", getIsLeft(no40)); // 0 (direito)

    printf("\n========== DESTRUIÇÃO ==========\n");
    destroiTree(arvore);
    printf("Árvore destruída. Memória liberada!\n");

    return 0;
}