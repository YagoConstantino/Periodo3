#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *father;
    int isLeft;
    int info;
    struct node *left;
    struct node *rigth;

}Node;

typedef Node* Tree;

int getInfo(Node* no);
Node *getRight(Node* no);
Node *getLeft(Node* no);
Node *getFather(Node* no);
Node *getBrother(Node* no);
int isLeft(Node* no);
//int isRight(Node* no);
Node* createNode(int x, Node* pai, int isLeft);
void insertBST(Tree* arvore, int x);
void inorderTraversal(Node* root);
void indesorderTraversal(Node* root);
int contarValores(Node* root);
int valorTotalArvore(Node* root);
int profundidade(Node* root); 

Tree makeTree(int x);
void setRight(Node* no,int x);
void setLeft(Node* no,int x);
void destroiTree(Tree arvore);
