#include <iostream>
#include "tad.h"
using namespace std;

Node* criaLista(){
    cout << "Lista criada com sucesso!" << endl;
    return NULL;
}

int vaziaLista(Node *lista){
    if (lista)
        return 0;
    else return 1;
}

Node* novoNoLista(int elem){
    Node *novo;
    novo = new Node;
    novo->info = elem;
    novo->prox = NULL;
    cout << "Elemento " << elem << " inserido com sucesso!" << endl;
    return novo;
}

Node* insereIniLista(Node* lista, int elem){
    Node *novo;
    novo = novoNoLista(elem);
    novo->prox = lista;
    lista = novo;

    return lista;
}

void printLista(Node *lista){
    if(!vaziaLista(lista)){
        Node *aux = lista;
        while (aux){
            cout << aux->info << " -> ";
            aux = aux->prox;
        }
        cout << "|X|" << endl;
    }else{
        cout << "Lista vazia!" << endl;
    }

}

Node* removeIniLista(Node *lista){
    if(!vaziaLista(lista)){
        Node *aux = lista;
        lista = lista->prox;
        delete aux;
    }else{
        cout << "Não foi possível remover! Lista esta vazia!" << endl;
    }
    return lista;
}

Node* esvaziarLista(Node *lista){
    while(!vaziaLista(lista)){
        lista = removeIniLista(lista);
    }
    return lista;
}

Node* insereFimLista(Node *lista, int elem){
    Node *novo;
    novo = novoNoLista(elem);
    Node *aux = lista;
    if(!vaziaLista(lista)){
        while(aux->prox)
            aux = aux->prox;//percorre ate o ultimo elemento
    aux->prox = novo;
    }else{
        lista = novo;
    }
    return lista;
}

Node* removeFimLista(Node *lista){
    if(!vaziaLista(lista)){
        Node *aux, *ant;
        aux = lista;
        ant = NULL;
        //posiciona aux no ultimo elemento
        while(aux->prox){
            ant = aux;
            aux = aux->prox;
        }
        //verifico se a lista tem mais de um elemento
        if(aux != lista){
            ant->prox = NULL;
        }else{
            lista = NULL;
        }
        delete aux;
    }else{
        cout << "Não foi possível remover! Lista ja esta vazia!" << endl;
    }
    return lista;
}

Node* insereOrdLista(Node *lista, int elem){
    Node *novo;
    novo = novoNoLista(elem);
    if(!vaziaLista(lista)){
        //insere no meio ou começo
        if(novo->info > lista->info){
            //insere no meio
            Node *aux, *ant;
            aux = lista;
            ant = NULL;
            while (aux && elem > aux->info){
                ant = aux;
                aux = aux->prox;
            }
            ant->prox = novo;
            novo->prox = aux;
        }else{
        //se novo é o menor elemento da lista
            novo->prox = lista;
            lista = novo;
        }
    }else{
        //insere primeiro elemento
        lista = novo;
    }
    return lista;
}

Node* removeElemLista(Node *lista, int elem){
    if(!vaziaLista(lista)){
        Node *aux, *ant;
        aux = lista;
        ant = NULL;

        while(aux && aux->info != elem){
            ant = aux;
            aux = aux->prox;
        }
        if(aux){
            if(aux != lista){
                ant->prox = aux->prox;
            }else{
                lista=lista->prox;
            }
            delete aux;
            cout << "Elemento " << elem << " excluído com sucesso" << endl;
        }else{
            cout << "Não foi possível remover! Elemento não encontrado!" << endl;
        }
    }else{
        cout << "Não foi possível remover! Lista esta vazia!" << endl;
    }
    return lista;
}

Node* buscaElementoLista(Node *lista, int elem){
    if(!vaziaLista(lista)){
        Node *aux = lista;
        while(aux && aux->info != elem){
            aux = aux->prox;
        }
        return aux;
    } else return NULL;
}

void setElementoLista(Node *pEdit, int edit){
    if(pEdit){
        pEdit->info = edit;
    }
}

int getElementoLista(Node *pAcess){
    if(pAcess){
        return pAcess->info;
    }
}

int maxLista(Node *lista){
    if(vaziaLista(lista)){
        cout << "Lista vazia";
        return 0;
    }

    int max = lista->info;
    Node * aux = lista;
    while(aux){
        if(aux->info > max) max = aux->info;
        aux = aux->prox;
    }
    cout << "Maior elemento encontrado foi " << max << endl;
    return max;
}

int minLista(Node * lista){
    if(vaziaLista(lista)){
        cout << "Lista vazia";
        return 0;
    }
    int min = lista->info;
    Node * aux = lista;
    while(aux){
        if(aux->info < min) min = aux->info;
        aux = aux->prox;
    }
    cout << "Menor elemento encontrado foi " << min << endl;
    return min;
}

int mediaLista(Node *lista){
    if(vaziaLista(lista)){
        cout << "Lista vazia";
        return 0;
    }
    int total = 0;
    int qnt = 0;
    Node * aux = lista;
    while(aux){
        total += (*aux).info;
        qnt++;
        aux = (*aux).prox;
    }

    int media = total / qnt;
    cout << "Média da lista foi " << media << endl;
    return media;
}

Node* appendLista(Node* L1,Node* L2){
    Node * aux = L1->prox;
    while(aux->prox){
        aux = aux->prox;
    }
    aux->prox = L2;
    
    cout << "Lista L2 concatenada com L1" << endl;
    return L1;
}


Node* reverseLista(Node* lista){
    Node * reverse = criaLista();
    Node * aux = lista;

    while(aux){
        cout << aux->info << endl;
        reverse = insereIniLista(reverse, aux->info);
        aux = aux->prox;
    }

    cout << "Lista invertida" << endl;
    return reverse;
}

int isSubLista(Node* L1, Node* L2){
    Node * aux = L1;

    while(aux){
        if(&aux->prox == &L2->prox){
            cout << "É UMA SUBLISTA"  << endl;
            return 1;
        }
        aux = aux->prox;
    }
    cout << "NÃO É UMA SUBLISTA"  << endl;
    return 0;
} 

int lenLista(Node *lista){
    int len = 0;
    Node * aux = lista;
    while(aux){
        len++;
        aux = (*aux).prox;
    }
    cout << "Existem " << len << " elementos na lista" << endl;
    return len; 
}