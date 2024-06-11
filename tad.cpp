//arquivo com as definições de tipos abstratos de dados utilizados!

struct node{
    int info;
    struct node *prox;
};

typedef struct node Node;

struct pilha{
    Node *topo;
};

typedef struct pilha Pilha;