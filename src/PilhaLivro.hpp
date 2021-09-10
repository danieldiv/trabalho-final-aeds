/*
    este .hpp sera responsavel pela estrutura da pilha de livros que uma pessoa pegar
*/

#ifndef PILHA_LIVRO_H
#define PILHA_LIVRO_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "estante.hpp"

using namespace std;

typedef struct ItemPilha ItemPilha;
typedef struct BlockPilha BlockPilha;
typedef struct PilhaLivro PilhaLivro;

struct ItemPilha {
	int val;
	int idEstante;
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
void PimprimeLivroPessoa(PilhaLivro *p);
int sizeLivroPilha(PilhaLivro *p);

#endif