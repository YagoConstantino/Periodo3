#ifndef  _ARVORE_H
#define  _ARVORE_H
#include <stdio.h>
#include <stdlib.h>

/*
-Arvores são tipos especiais de grafos
-Qualquer par de vértices está conectado por apenas uma aresta
-Grafo conexo (existe um caminho entre quaisquer dois vértices) e acíclico(não retorna ao começo, não fecha um ciclo)
*/

/*
    Vertices, são as entidades que representam os elementos que formam o grafo, podem ser nós,computadores em uma rede,
    Organização de pastas em um PC etc, dependendo do problema.

    Arestas, são as conexões entre dois vértices
*/

typedef struct node
{
    struct node *father;
    struct node *left;
    struct node *right;
    int isLeft;
    int info;
}Node;

typedef Node* Tree;

Node *createNode(int x,Node* pai,int left);
Tree makeTree(int x);
void destroiTree(Tree arvore);

void iterativeInsertBST(Tree* arvore, int x);
void recursiveInsertBST(Tree* arvore,int x);

int getInfo(Node* no);
Node *getFather(Node* no);
Node *getLeft(Node* no);
Node *getRigth(Node* no);
int getIsLeft(Node* no);

void setRight(Node* no,int x);
void setLeft(Node* no,int x);

void inOrder(Node* root);
void inDesorder(Node* root);
void preOrder(Node* root);
void posOrder(Node* root);

Node *TreeSerch(Node* root,int k);
Node *TreeSerchIterative(Node* root,int k);
int contarValores(Node* root);
int valorTotalArvore(Node* root);



/*retorna os valores */
int iterativeTreeMinimun(Node *root);
int iterativeTreeMaximun(Node *root);

int recursiveTreeMinimun(Node *root);
int recursiveTreeMaximun(Node *root);

/*Retorna os Nós*/

Node* NODEiterativeTreeMinimun(Node *root);
Node* NODEiterativeTreeMaximun(Node *root);

Node* NODErecursiveTreeMinimun(Node *root);
Node* NODErecursiveTreeMaximun(Node *root);

Node* TreeSucessor(Node* root);
Node* TreePredecessor(Node* root);

#endif