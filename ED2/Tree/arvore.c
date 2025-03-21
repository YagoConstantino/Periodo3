#include "arvore.h"

int getInfo(Node *no)
{
    if(no != NULL)
        return no->info;
    else
    {
        printf("Ponteiro para Nó invalido na Função getInfo, return -1 \n\n");
        return -1;
    }    
}

Node *getRight(Node* no)
{
    if(no != NULL)
    {
        return no->rigth;
    }
    else
    {
        printf("Ponteiro para Nó invalido na Função getRigth, return NULL \n\n");
        return NULL;
    }    
}

Node *getLeft(Node *no)
{
    if(no != NULL)
    {
        return no->left;
    }
    else
    {
        printf("Ponteiro para Nó invalido na Função getLeft, return NULL \n\n");
        return NULL;
    }    
}

Node *getFather(Node *no)
{
    if(no != NULL)
    {
        return no->father;
    }
    else
    {
        printf("Ponteiro para Nó invalido na Função getFather, return NULL \n\n");
        return NULL;
    }    
}

Node *getBrother(Node *no)
{
    if(no != NULL)
    {
        if(no->father != NULL)
        {
            if(no->isLeft)
                return no->father->rigth;
            else
                return no->father->left;    
        }
        else
        {
            printf("Ponteiro para No->father invalido na Função getBrother, return NULL \n\n");
            return NULL;
        }
    }
    else
    {
        printf("Ponteiro para Nó invalido na Função getBrother, return NULL \n\n");
        return NULL;
    }    
}

int isLeft(Node *no)
{
    if(no != NULL)
        return no->isLeft;
    else
    {
        printf("Ponteiro para Nó invalido na Função isLeft, return -1 \n\n");
        return -1;
    }      
}

Node* createNode(int x, Node* pai, int isLeft)
{
    Node* novo = (Node*)malloc(sizeof(Node));
    if( novo != NULL)
    {
        novo->info = x;
        novo->father = pai;
        novo->isLeft = isLeft;
        novo->rigth = NULL;
        novo->left = NULL;
        return novo;
    }
    return NULL;
}

void insertBST(Tree* arvore, int x)
{
    if(*arvore == NULL)
    {
        *arvore = createNode(x,NULL,0);
        return;
    }

    Node* current = *arvore;
    Node* parent = NULL;

    while(current != NULL)
    {
        parent = current;
        if(x < current->info)
            current = parent->left;

        else if (x > current->info)
            current = parent->rigth;

        else
        {
            printf("%d já existe!\n", x);
            return; 
        }
    }

    if(x < parent->info)
        parent->left = createNode(x,parent,1);
    
    else
        parent->rigth = createNode(x,parent,0);    

}

Tree makeTree(int x)
{
    return createNode(x,NULL,0);
}

void setRight(Node* no,int x)
{
    if(no != NULL)
        no->rigth = createNode(x,no,0);
    else
        printf("Ponteiro para Nó invalido na Função setRight \n\n");
}

void destroiTree(Tree arvore)
{
    if(arvore != NULL)
    {
        destroiTree(arvore->left);
        destroiTree(arvore->rigth);
        free(arvore);
    }
}

void setLeft(Node* no,int x)
{
    if(no!=NULL)
        no->left = createNode(x,no,1);
    else
    printf("Ponteiro para Nó invalido na Função setLeft \n\n");
}



void inorderTraversal(Node* root) 
{
    if (root != NULL) 
    {
        inorderTraversal(root->left);
        printf("%d ", root->info);
        inorderTraversal(root->rigth);
    }
}

void indesorderTraversal(Node* root) 
{
    if (root != NULL) 
    {
        indesorderTraversal(root->rigth);
        printf("%d ", root->info);
        indesorderTraversal(root->left);
    }
}

int contarValores(Node* root)
{
    
    if (root== NULL) return 0;

    return 1 + contarValores(root->left) + contarValores(root->rigth);
    
}
int valorTotalArvore(Node* root)
{
    if(root == NULL ) return 0;

    return root->info + valorTotalArvore(root->left) + valorTotalArvore(root->rigth);
}

int profundidade(Node* root)
{
    if(root == NULL) return 0;
    int esq = profundidade(root->left);
    int dir = profundidade (root->rigth);

    int maior;
    if(esq > dir) maior = esq;
    else maior = dir;
    return 1 + maior;
}
