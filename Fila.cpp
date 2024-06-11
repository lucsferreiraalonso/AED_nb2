#include <iostream>
#include "tad.h"
#include <clocale>
using namespace std;


/*
FUNÇÃO: criaFila
RESUMO: Cria uma nova fila vazia
PARAM: void
RETORNO: Fila* (ponteiro para a fila criada)
*/
Fila* criaFila(){
	//armazena o espaço para a fila
	Fila* fila = new Fila;
	fila->inicio = NULL;
	fila->fim = NULL;
	return fila;
}

/*
FUNÇÃO: vazia
RESUMO: verifica se a fila esta vazia
PARAM: Fila* fila (ponteiro para a fila)
RETORNO: int (valor de teste para a condição de vazio)
*/
int vaziaFila(Fila *fila){
	if(fila->inicio == NULL)
		return 1;
	else return 0;
}

/*
FUNÇÃO: enqueue
RESUMO: insere elemento no fim da fila
PARAM: Fila* fila (ponteiro para a fila), int valor (valor a ser inserido)
RETORNO: void
*/
void enqueue(Fila* fila, int valor){
	Node* novo = new Node;
	novo->info = valor;
	novo->prox = NULL; //inserido no final
	if(vaziaFila(fila)){
		fila->inicio = novo;
		fila->fim = novo;
	}else{
		(fila->fim)->prox = novo;
		fila->fim = novo;
	}
}

/*
FUNÇÃO: dequeue
RESUMO: remove e retorna o elemento do inicio da fila
PARAM: Fila* fila (ponteiro para a fila)
RETORNO: int (valor removido da fila)
*/
int dequeue(Fila* fila){
	Node* aux;
	int valor;
	aux = fila->inicio;
	valor = aux->info;
	fila->inicio = aux->prox;
	//se esvaziou a fila, fila->fim tbm tem que ficar nula
	if(vaziaFila(fila))
		fila->fim = NULL;
	delete(aux);
	return valor;
}

/*
FUNÇÃO: first
RESUMO: retorna o elemento do inicio da fila
PARAM: Fila* fila (ponteiro para a fila)
RETORNO: int (valor da cabeça da fila)
*/
int first(Fila* fila){
    if (!vaziaFila(fila))
        return (fila->inicio)->info;
}

/*
FUNÇÃO: destroiFila
RESUMO: exclui todo conteúdo da fila
PARAM: Fila* (ponteiro para a fila)
RETORNO: nada
*/
void destroiFila(Fila *fila){
    while(!vaziaFila(fila))
        dequeue(fila);
}

/*
FUNÇÃO: print
RESUMO: imprime a fila (ERRADO, apenas para controle)
PARAM: Fila* (ponteiro para a fila)
RETORNO: void
*/
void printFilaControle(Fila* fila){
	Node* aux = fila->inicio;
	cout << "Inicio: ";
	while(aux){
		cout << "| " << aux->info << " |-->";
		aux = aux->prox;
	}
	cout << "X" << endl;
}

// *************************************************************************************************************************

void imprimeFila(Fila * fila){
	if(vaziaFila(fila)){
		cout << "FILA VAZIA" << endl;
		return;
	}
	Fila * aux = criaFila();
	int pos = 0;
	while(!vaziaFila(fila)){
		int elem = dequeue(fila);
		pos++;
		cout << pos << "º Posição = " << elem << endl;
		enqueue(aux, elem);
	}

	while(!vaziaFila(aux)){
		int elem = dequeue(aux);
		enqueue(fila, elem);
	}
	cout << endl;
}

Fila * editElemFila(Fila * fila, int target, int new_value){
	if(vaziaFila(fila)){
		cout << "FILA VAZIA" << endl;
		return fila;
	}
	Fila * aux = criaFila();
	int pos = 0;
	bool editState = false; // Trava para editar somente UM elemento da fila;
	while(!vaziaFila(fila)){
		pos++;
		int elem = dequeue(fila);
		if(elem == target && !editState) {
			cout << "Valor " << target << ", na " << pos << "º posição alterado para " << new_value << endl;
			enqueue(aux, new_value);
			editState = true;
		}
		else enqueue(aux, elem);
	}

	while(!vaziaFila(aux)){
		int elem = dequeue(aux);
		enqueue(fila, elem);
	}

	return fila;
}

Fila * removeElemFila(Fila * fila, int target){
	if(vaziaFila(fila)){
		cout << "FILA VAZIA" << endl;
		return fila;
	}
	int pos = 0;
	Fila * aux = criaFila();
	bool isRemoved = false; // Trava para remover somente um elemento da fila;
	while(!vaziaFila(fila)){
		pos++;
		int elem = dequeue(fila);
		if(elem == target && !isRemoved) {
			cout << "Valor " << target << ", na " << pos << "º posição removido" << endl;
			isRemoved = true;
		}
		else enqueue(aux, elem);
	}
	if(!isRemoved) cout << "Elemento " << target << " não encontrado na fila" << endl;

	while(!vaziaFila(aux)){
		int elem = dequeue(aux);
		enqueue(fila, elem);
	}

	return fila;
}

Fila * removeDuplicatasFila(Fila * fila){
	if(vaziaFila(fila)){
		cout << "Fila vazia" << endl;
		return fila;
	}
	int length = 0;
	int * values = (int*) malloc(sizeof(int) * length);
	Fila * aux = criaFila();

	while(!vaziaFila(fila)){
		int val = dequeue(fila);
		int repeat = 0;
		length++;
		values = (int*) realloc(values, sizeof(int) * length);
		values[length - 1] = val;

		for(int i = 0; i < length; i++){
			if(values[i] == val) repeat++;
			if(repeat > 1) break; // Se ele já se repete (+ de 1 vez), não é necessário percorrer o resto da fila
		}

		if(repeat <= 1) enqueue(aux, val);
	}

	while(!vaziaFila(aux)){
		int elem = dequeue(aux);
		enqueue(fila, elem);
	}

	cout << "Elementos duplicados removidos da fila" << endl;
	return fila;
}

Fila * removeParesFila(Fila * fila){
	if(vaziaFila(fila)){
		cout << "Fila vazia" << endl;
		return fila;
	}
	Fila * aux = criaFila();
	while(!vaziaFila(fila)){
		int val = dequeue(fila);
		if(val % 2 == 1) enqueue(aux, val);
	}

	while(!vaziaFila(aux)){
		int elem = dequeue(aux);
		enqueue(fila, elem);
	}
	cout << "Elementos pares removidos da fila" << endl;
	return fila;
}