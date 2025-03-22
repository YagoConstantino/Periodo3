#include "Arvore.h"

Node *createNode(int x,Node* pai,int left)
{
    Node* novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL)
    {
        novo->father = pai;
        novo->left = NULL;
        novo->right = NULL;
        novo->info = x;
        novo->isLeft = left;
    }
    return novo;
}

Tree makeTree(int x)
{
    return createNode(x,NULL,0);
}

void destroiTree(Tree arvore)
{
    if(arvore != NULL)
    {
        destroiTree(arvore->left);
        destroiTree(arvore->right);
        free(arvore);
    }
}

void iterativeInsertBST(Tree *arvore, int x)
{
    if(*arvore == NULL)
    {
        *arvore = makeTree(x);
        return;
    }
    Node* atual = *arvore;
    Node* pai = NULL;
    while(atual != NULL)
    {
        pai = atual;
        if(x < pai->info)
            atual = atual->left;
        else if (x > pai->info)
            atual = atual->right;
        else
        {
            printf("Valor %d já existe!\n", x); // Trata duplicatas
            return;
        }        
    }
    
    if(x<pai->info)
        setLeft(pai,x);
    else
        setRight(pai,x);    
}

int getInfo(Node *no)
{
    if(no != NULL)
        return no->info;
    return 0;    
}

Node *getFather(Node *no)
{
    if(no != NULL)
        return no->father;
    
    return NULL;
}

Node *getLeft(Node *no)
{
    if(no != NULL)
        return no->left;
    
    return NULL;    
}

Node *getRigth(Node *no)
{
    if(no != NULL)
        return no->right;
    
    return NULL;   
}

int getIsLeft(Node *no)
{
    if(no != NULL)
        return no->isLeft;
    
    return 0;  
}

void setRight(Node *no, int x)
{
    no->right = createNode(x,no,0);
}

void setLeft(Node *no, int x)
{
    no->left = createNode(x,no,1);
}

void inOrder(Node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d ",root->info);
        inOrder(root->right);
    }
}

void inDesorder(Node *root)
{
    if(root != NULL)
    {
        inDesorder(root->right);
        printf("%d ",root->info);
        inDesorder(root->left);
    }
}

void preOrder(Node *root)
{
    if(root != NULL)
    {
        printf("%d ",root->info);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void posOrder(Node *root)
{
    if(root != NULL)
    {
        posOrder(root->left);
        posOrder(root->right);
        printf("%d ",root->info);
    }
}

Node *TreeSerch(Node *root, int k)
{
    if(root != NULL)
    {
        if(root->info == k)
            return root;
        else
        {
            if(k>root->info)
                return TreeSerch(root->right,k);
            else
                return TreeSerch(root->left,k);   
        }    
    }
    return NULL;

    /* deepseek, mais claro porém nao fui eu que fiz
    // Caso base: árvore vazia ou chave encontrada
    if (root == NULL || root->info == k) {
        return root;
    }

    // Se a chave for maior, busca na subárvore direita
    if (k > root->info) {
        return TreeSearch(root->right, k);
    }
    // Se a chave for menor, busca na subárvore esquerda
    else {
        return TreeSearch(root->left, k);
    }

    */
}
Node *TreeSerchIterative(Node *root, int k)
{
    Node* atual = root;
    while(atual != NULL && atual->info != k)
    {
        if(k > atual->info)
            atual = atual->right;  // Vai para a direita se 'k' for maior
        else
            atual = atual->left;   // Vai para a esquerda se 'k' for menor
    }
    return atual;
}
int contarValores(Node *root)
{
    if(root == NULL) return 0;
    return 1 + contarValores(root->left) + contarValores(root->right);
}

int valorTotalArvore(Node *root)
{
    if(root == NULL )return 0;
    
    return root->info + valorTotalArvore(root->left) + valorTotalArvore(root->right);
}

int iterativeTreeMinimun(Node *root)
{
    if(root == NULL)
    {
        printf("Arvore Vazia , -1 \n");
        return -1;
    }
    Node* atual = root;
    while(atual->left != NULL)
        atual = atual->left;
    
    return atual->info;    
}

int iterativeTreeMaximun(Node *root)
{
    if(root == NULL)
    {
        printf("Arvore Vazia , -1 \n");
        return -1;
    }

    Node* atual = root;
    while(atual->right != NULL)
        atual = atual->right;
    
    return atual->info;   
}

int recursiveTreeMinimun(Node *root)
{
    if(root == NULL)
    {
        printf("Arvore Vazia , -1 \n");
        return -1;
    }

    if(root->left == NULL) return root->info;

    return recursiveTreeMinimun(root->left);
}

int recursiveTreeMaximun(Node *root)
{
    if(root == NULL)
    {
        printf("Arvore Vazia , -1 \n");
        return -1;
    }

    if(root->right == NULL) return root->info;

    return recursiveTreeMaximun(root->right);
}

Node *NODEiterativeTreeMinimun(Node *root)
{
    if(root == NULL)
    {
        printf("Arvore Vazia , NULL \n");
        return NULL;
    }
    Node* atual = root;
    while(atual->left != NULL)
        atual = atual->left;
    
    return atual;    
}

Node *NODEiterativeTreeMaximun(Node *root)
{
    if (root == NULL) 
    {
        printf("Árvore vazia, NULL\n");
        return NULL;
    }

    Node *atual = root;
    while (atual->right != NULL) 
    {
        atual = atual->right; // Avança até o nó mais à direita
    }
    return atual;
}

Node *NODErecursiveTreeMinimun(Node *root)
{
    /*if(root == NULL)
    {
        printf("Arvore Vazia , NULL \n");
        return NULL;
    }

    if(root->left == NULL) return root;

    return NODErecursiveTreeMinimun(root->left!!!!!! so faltou o left);*/

    if (root == NULL) {
        printf("Árvore vazia, NULL\n");
        return NULL;
    }

    // Encontrou o nó mais à esquerda (mínimo)
    if (root->left == NULL) {
        return root;
    }

    // Busca recursiva na subárvore esquerda
    return NODErecursiveTreeMinimun(root->left); // Correção crítica: root->left
}

Node *NODErecursiveTreeMaximun(Node *root)
{
    if(root == NULL)
    {
        printf("Arvore Vazia , NULL \n");
        return NULL;
    }

    if(root->right == NULL) return root;

    return NODErecursiveTreeMaximun(root);
}
