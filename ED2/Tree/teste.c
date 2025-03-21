#include "arvore.h"
#include <stdio.h>

int main() {
    Tree minhaArvore = makeTree(10);
    
    insertBST(&minhaArvore, 5);
    insertBST(&minhaArvore, 15);
    insertBST(&minhaArvore, 3);
    insertBST(&minhaArvore, 7);
    insertBST(&minhaArvore, 12);
    insertBST(&minhaArvore, 18);
    insertBST(&minhaArvore, 32);
    insertBST(&minhaArvore, 11);
    insertBST(&minhaArvore, 57);
    insertBST(&minhaArvore, 28);
    insertBST(&minhaArvore, 1);
    insertBST(&minhaArvore,23);
    insertBST(&minhaArvore,24);
    insertBST(&minhaArvore,36);
    insertBST(&minhaArvore,14);
    insertBST(&minhaArvore,99);

    printf(" SOOMA %d\n\n",5+15+3+7+12+18+32+11+57+28+1+10+23);
    
    printf("Percorrendo a árvore em ordem:");
    inorderTraversal(minhaArvore);
    printf("\n");
    printf("Percorrendo a árvore em ordem inversa :");
    indesorderTraversal(minhaArvore);
    printf("\n");
    printf("Numeros Totais de Nós %d\n\n",contarValores(minhaArvore));
    printf("Soma total dos  Nós %d\n\n",valorTotalArvore(minhaArvore));
    printf("PROFUNDIDADE dos  Nós %d\n\n",profundidade(minhaArvore));
    
    // Testando algumas funções
    Node* node = minhaArvore->left; // Pegando o nó com valor 5
    printf("Info do nó 5: %d\n", getInfo(node));
    printf("Pai do nó 5: %d\n", getInfo(getFather(node)));
    printf("Irmão do nó 5: %d\n", getInfo(getBrother(node)));

    destroiTree(minhaArvore);
    
    return 0;
}
