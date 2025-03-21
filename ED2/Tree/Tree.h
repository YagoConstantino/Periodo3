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


int getInfo(Node* no);
Node *getRight(Node* no);
Node *getLeft(Node* no);
Node *getFather(Node* no);
Node *getBrother(Node* no);
int isLeft(Node* no);
int isRight(Node* no);

typedef Node* Tree;

Tree makeTree(int x);
void setRigth(Node* no,int x);
void setLeft(Node* no,int x);
void printTree(Tree pai);
void printTreeRec(Node*node,int space);