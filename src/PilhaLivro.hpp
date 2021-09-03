#ifndef PILHA_LIVRO_H
#define PILHA_LIVRO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ItemPilha ItemPilha;
typedef struct BlockPilha BlockPilha;
typedef struct Pilha Pilha;

struct ItemPilha {
	int val;
};

struct BlockPilha {
	ItemPilha dado;
	BlockPilha *prox;
};

struct PilhaLivro {
	BlockPilha *base;
	BlockPilha *top;
};

void FPVazia(PilhaLivro *p);
void Push(PilhaLivro *p, ItemPilha d);
void Pop(PilhaLivro *p, ItemPilha *d);
void Pimprime(PilhaLivro *p);

#endif