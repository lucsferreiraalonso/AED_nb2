#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"
#include "Pilha.h"
#include "Fila.h"
#include <clocale>

using namespace std;

int main() {

    //padronizando acentuação
    setlocale(LC_ALL, "");

    cout << " *** FILAS ***" << endl;

    Fila *fila = criaFila();
    enqueue(fila, 1);
    enqueue(fila, 2);
    enqueue(fila, 3);
    enqueue(fila, 4);
    enqueue(fila, 5);
    enqueue(fila, 4);
    enqueue(fila, 3);
    enqueue(fila, 2);
    enqueue(fila, 1);
    imprimeFila(fila);
    fila = editElemFila(fila, 5, 7);
    imprimeFila(fila);

    fila = removeElemFila(fila, 3);
    imprimeFila(fila);

    fila = removeDuplicatasFila(fila);
    imprimeFila(fila);

    fila = removeParesFila(fila);
    imprimeFila(fila);


    cout << "*** Listas ***" << endl;
    Node *lista = criaLista();
    lista = insereIniLista(lista, 1);
    lista = insereIniLista(lista, 2);
    lista = insereIniLista(lista, 3);
    lista = insereIniLista(lista, 2);
    lista = insereIniLista(lista, 1);
    cout << "Lista 1:\n";
    printLista(lista);
    cout << endl;

    Node *lista2 = criaLista();
    lista2 = insereIniLista(lista2, 5);
    lista2 = insereIniLista(lista2, 7);
    cout << "Lista 2:\n";
    printLista(lista2);
    cout << endl;

    lista = appendLista(lista, lista2);
    cout << "lista2 concatenada com lista: ";
    printLista(lista);
    cout << endl;

    Node *reverse = reverseLista(lista);
    cout << "Lista original: ";
    printLista(lista);
    cout << "Lista reversa: ";
    printLista(reverse);
    cout << endl;

    int val = isSubLista(reverse, lista2);
    int min = minLista(lista);
    int max = maxLista(lista);
    int len = lenLista(lista);
    int media = mediaLista(lista);
    cout << endl;

    cout << "*** PILHAS ***" << endl;

    Pilha *p = criaPilha();
    p = push(p, 1);
    p = push(p, 2);
    p = push(p, 3);
    p = push(p, 4);
    p = push(p, 5);
    p = push(p, 6);
    p = push(p, 7);
    p = push(p, 8);
    p = push(p, 9);
    p = push(p, 0);
    p = push(p, 9);
    p = push(p, 8);
    p = push(p, 7);
    p = push(p, 6);
    p = push(p, 5);
    p = push(p, 4);
    p = push(p, 3);
    p = push(p, 2);
    printPilhaControle(p);

    cout << endl;
    p = removeDuplicatasPilha(p);
    printPilhaControle(p);

    cout << endl;
    p = removeElemPilha(p, 7);
    printPilhaControle(p);

    cout << endl;
    p = removeParesPilha(p);
    printPilhaControle(p);
}