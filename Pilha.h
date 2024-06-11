#ifndef PILHA_H

#define PILHA_H

#include "tad.h"
Pilha* criaPilha();
int vaziaPilha(Pilha* pilha);
Pilha* push(Pilha* pilha, int valor);
int pop(Pilha* pilha);
int top(Pilha* pilha);
void destroiPilha(Pilha* pilha);
void printPilhaControle(Pilha* pilha);
int buscaElemPilha(Pilha * pilha, int target);
Pilha* removeElemPilha(Pilha * pilha, int target);
Pilha * removeParesPilha(Pilha * pilha);
Pilha * removeDuplicatasPilha(Pilha * pilha);
#endif // PILHA_H