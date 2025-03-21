#include "Tree.h"
// Função auxiliar para criar um nó (simplifica setLeft/setRight)
Node* createNode(int x, Node* pai, int isLeft) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->info = x;
        newNode->father = pai;
        newNode->isLeft = isLeft;
        newNode->left = NULL;
        newNode->rigth = NULL;
    }
    return newNode;
}

// Função principal de inserção com while
void insertBST(Tree* arvore, int x) {
    if (*arvore == NULL) {
        *arvore = createNode(x, NULL, 0); // Cria raiz se a árvore estiver vazia
        return;
    }

    Node* current = *arvore;
    Node* parent = NULL;

    // Loop para encontrar o local de inserção
    while (current != NULL) {
        parent = current;
        if (x < current->info) {
            current = current->left;
        } else if (x > current->info) {
            current = current->rigth;
        } else {
            printf("%d já existe!\n", x);
            return;
        }
    }

    // Insere o novo nó como filho de 'parent'
    if (x < parent->info) {
        parent->left = createNode(x, parent, 1); // Filho esquerdo
    } else {
        parent->rigth = createNode(x, parent, 0); // Filho direito
    }
}

int main() {
    Tree arvore = NULL; // Árvore inicialmente vazia

    int number = 50;
    while(number != -1)
    {
        scanf("%d",&number);
        insertBST(&arvore,number);
    }
    printTree(arvore);

    return 0;
}