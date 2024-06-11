#include <iostream>
#include "tad.h"
#include <clocale>
using namespace std;

/*
FUNÇÃO: criaPilha
RESUMO: Cria uma nova pilha vazia
PARAM: void
RETORNO: Pilha* (ponteiro para a pilha);
*/
Pilha* criaPilha(){
	Pilha* p = new Pilha;
	p->topo = NULL;
	return p;
}

/*
FUNÇÃO: vazia
RESUMO: verifica se a pilha esta vazia
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: int (1 se esta vazia, 0 se não estiver)
*/
int vaziaPilha(Pilha* pilha){
	if( pilha->topo == NULL)
		return 1;
	else return 0;
}

/*
FUNÇÃO: push
RESUMO: empilha novo elemento na pilha
PARAM: Pilha* (ponteiro para a pilha), int (valor a ser empilhado);
RETORNO: Pilha* (ponteiro para a pilha);
*/
Pilha* push(Pilha* pilha, int valor){
	Node* novo = new Node;
	novo->info = valor;
	novo->prox = pilha->topo;
	pilha->topo = novo;
	return pilha;
}

/*
FUNÇÃO: pop
RESUMO: desempilha o elemento no topo da pilha e retorna seu valor
PARAM: Pilha* (ponteiro para a pilha), int (valor a ser desempilhado);
RETORNO: Pilha* (ponteiro para a pilha);
*/
int pop(Pilha* pilha){
    Node* aux = pilha->topo;
    int valor;
    if(!vaziaPilha(pilha)){
        valor = aux->info;
        pilha->topo = (pilha->topo)->prox;
        delete aux;
    } else cout << "pilha vazia!" << endl;
    return valor;
}

/*
FUNÇÃO: top
RESUMO: informa o valor do primeiro elemento da pilha
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: int (valor da informação armazenado no topo)
*/
int top(Pilha* pilha){
	if (!vaziaPilha(pilha))
        return (pilha->topo)->info;
    else cout << "pilha vazia!";
}

/*
FUNÇÃO: destroiPilha
RESUMO: exclui todo conteúdo da pilha
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: nada
*/
void destroiPilha(Pilha* pilha){
	while (!vaziaPilha(pilha))
        pop(pilha);
    cout << "pilha destruída com sucesso!" << endl;
}

/*
FUNÇÃO: print
RESUMO: imprime a pilha
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: void
*/
void printPilhaControle(Pilha* pilha){
	Node* aux = pilha->topo;
	cout << "____" << endl;
	while(aux){
		cout << "| " << aux->info << " |\n"<< "____" << endl;
		aux = aux->prox;
	}
	cout << "X" << endl;
}

int buscaElemPilha(Pilha * pilha, int target){
	Pilha * aux = criaPilha();
	int val;
	if(vaziaPilha(pilha)){
		cout << "Pilha vazia" << endl;
		return 0;
	}
	while(!vaziaPilha(pilha)){
		int elem = pop(pilha);
		if(elem == target) val = elem;
		aux = push(aux, elem);
	}
	while(!vaziaPilha(aux)){
		int elem = pop(aux);
		pilha = push(pilha, elem);
	}
	
	cout << (val == target ? "Elemento encontrado " : "Elemento não encontrado") << endl; 
	return val;
}



Pilha * removeElemPilha(Pilha * pilha, int target){
	if(vaziaPilha(pilha)){
		cout << "Pilha vazia" << endl;
		return pilha;
	}
	Pilha * aux = criaPilha();
	bool isRemove = false;// Trava para remover somente um elemento da PILHA

	while(!vaziaPilha(pilha)){
		int elem = pop(pilha);
		if(elem == target && !isRemove) {
			cout << "Elemento "<< elem <<" removido" << endl;
			isRemove = true;
		}
		else aux = push(aux, elem);
	}
	while(!vaziaPilha(aux)){
		int elem = pop(aux);
		pilha = push(pilha, elem);
	}

	return pilha;
}

Pilha * removeParesPilha(Pilha * pilha){
	Pilha * aux = criaPilha();
	if(vaziaPilha(pilha)){
		cout << "Pilha vazia" << endl;
		return pilha;
	}
	while(!vaziaPilha(pilha)){
		int elem = pop(pilha);
		if(elem % 2 == 1) aux = push(aux, elem);
		else cout << "Elemento "<< elem <<" removido" << endl;
	}
	while(!vaziaPilha(aux)){
		int elem = pop(aux);
		pilha = push(pilha, elem);
	}
	cout << "Elementos pares removidos da pilha" << endl;
	return pilha;
}

Pilha * removeDuplicatasPilha(Pilha * pilha){
	if(vaziaPilha(pilha)){
		cout << "Pilha vazia" << endl;
		return pilha;
	}
	int length = 0;
	int * values = (int*) malloc(sizeof(int) * length);
	Pilha * aux = criaPilha();

	while(!vaziaPilha(pilha)){
		int val = pop(pilha);
		int repeat = 0;
		length++;
		values = (int*)realloc(values, sizeof(int) * length);
		values[length - 1] = val;

		for(int i = 0; i < length; i++){
			if(val == values[i]) repeat++;
			if(repeat > 1) break; // Se ele já se repete (+ de 1 vez), não é necessário percorrer o resto da pilha
		}
		if(repeat <= 1) aux = push(aux, val); 
	}

	while(!vaziaPilha(aux)){
		int elem = pop(aux);
		pilha = push(pilha, elem);
	}

	cout << "Elementos duplicados removidos" << endl;
	return pilha;
}
