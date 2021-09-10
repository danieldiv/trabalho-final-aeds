/*
    este .hpp sera responsavel pela estrutura do livro, bem como as suas operacoes
*/

#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <iostream>
#include <string.h>
#include <string>

using namespace std;

typedef struct ItemLivro ItemLivro;
typedef struct BlockLivro BlockLivro;
typedef struct Livro Livro;

struct ItemLivro {
	int id;
	int id_categoria;
	string str;
	char *nome;
	bool controle;
};

struct BlockLivro {
	ItemLivro data;
	BlockLivro *ant;
	BlockLivro *prox;
};

struct Livro {
	BlockLivro *first;
	BlockLivro *last;
};

void FLVazia(Livro *l);
void LInsert(Livro *l, ItemLivro item);
bool LRemove(Livro* l, ItemLivro item);
void printLivro(Livro *l);
void LImprimeLivroEstante(Livro *l);
ItemLivro LBusca(Livro *L, int idLivro);

int sizeLivro(Livro *l);

#endif