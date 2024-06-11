#ifndef TAD_H

#define TAD_H


struct node{
    int info;
    struct node *prox;
};
typedef struct node Node;

struct pilha{
    Node *topo;
};
typedef struct pilha Pilha;

struct fila{
    Node * inicio;
    Node * fim;
};

typedef struct fila Fila;


#endif