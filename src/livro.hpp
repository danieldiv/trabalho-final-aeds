#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <iostream>
#include <string.h>
#include <string>

// static int quanLivro = 0;
using namespace std;

typedef struct ItemLivro ItemLivro;
typedef struct BlockLivro BlockLivro;
typedef struct Livro Livro;

struct ItemLivro {
	int id;
	int id_categoria;
	int quantidade;
	string str;
	char *nome;
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
void LRemove(Livro *l, ItemLivro item);
void Swap(BlockLivro *a, BlockLivro *b);
void LImprimeLivro(Livro *l);
void LImprimeLivroEstante(Livro *l);

int sizeLivro(Livro *l);

#endif