#include "Tree.h"

void printTree(Tree pai)
{
    printf("Árvore:\n");
    printTreeRec(pai, 0);
    printf("\n");
}

void printTreeRec(Node *node, int space)
{
    if (node == NULL) {
        return;
    }

    // Aumenta a indentação para o próximo nível
    space += 4;

    // Processa o filho direito primeiro
    printTreeRec(node->rigth, space);

    // Imprime o nó atual com indentação
    printf("\n");
    for (int i = 4; i < space; i++) {
        printf(" ");
    }

    // Verifica se é a raiz ou um filho
    if (node->father == NULL) {
        printf("%d (Raiz)\n", node->info);
    } else {
        printf("%s: %d\n", node->isLeft ? "L" : "R", node->info);
    }

    // Processa o filho esquerdo
    printTreeRec(node->left, space);
}

int getInfo(Node *no)
{
    if(no)
        return no->info;
    else
    {
        printf("Ponteiro para Nó inválido (-1)\n");
        return -1;
    }    
}

Node *getRight(Node *no)
{
    if(no)
        return no->rigth;
    else
    {
        printf("Ponteiro para Nó inválido (NULL)\n");
        return NULL;
    }        
    
}

Node *getLeft(Node *no)
{
    if(no)
        return no->left;
    else
    {
        printf("Ponteiro para Nó inválido (NULL)\n");
        return NULL;
    }        
}

Node *getFather(Node *no)
{
    if(no)
        return no->father;
    else
    {
        printf("Ponteiro para Nó inválido (NULL)\n");
        return NULL;
    }        
}

Node *getBrother(Node *no)
{
    if(no)
    {
        if(no->father)
        {
            if(no->isLeft)
                return no->father->rigth;
                
            return no->father->left;    
        }
        else
        {
            printf("Ponteiro para Pai inválido, Este Nó é a raiz (NULL)\n");
        return NULL;
        }
    }
    else
    {
        printf("Ponteiro para Nó inválido (NULL)\n");
        return NULL;
    }       
}

int isLeft(Node *no)
{
    if(no)
        return no->isLeft;
    else
    {
        printf("Ponteiro para Nó inválido (False)\n");
        return 0;
    }   
}

int isRight(Node *no)
{
    if(no)
        return !no->isLeft;
    else
    {
        printf("Ponteiro para Nó inválido (False)\n");
        return 0;
    }   
}

Tree makeTree(int x)
{
    Node* root = (Node*)malloc(sizeof(Node));
    if(root)
    {
        root->father = NULL;
        root->info = x;
        root->isLeft = 0;
        root->left = NULL;
        root->rigth = NULL;
    }

    return root;
}

void setRigth(Node *no, int x)
{
    if(no)
    {

        if(no->rigth ==NULL)
        {
            Node* newNode = (Node*)malloc(sizeof(Node));
            if(newNode)
            {
                newNode->father = no;
                newNode->info = x;
                newNode->isLeft = 0;
                newNode->left = NULL;
                newNode->rigth = NULL;
            }
            no->rigth = newNode;
        }
    }
    else
    {
        printf("Ponteiro para Nó da Tree inválido\n");
        return ;
    }
}

void setLeft(Node *no, int x)
{
    if(no)
    {

        if(no->left ==NULL)
        {
            Node* newNode = (Node*)malloc(sizeof(Node));
            if(newNode)
            {
                newNode->father = no;
                newNode->info = x;
                newNode->isLeft = 1;
                newNode->left = NULL;
                newNode->rigth = NULL;
            }
            no->left = newNode;
        }
    }
    else
    {
        printf("Ponteiro para Nó da Tree inválido\n");
        return ;
    }
}
