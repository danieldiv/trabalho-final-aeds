#include "livro.hpp"

void FLVazia(Livro* l) {
	l->first = (BlockLivro*)malloc(sizeof(BlockLivro));
	l->last = l->first;
	l->first->prox = NULL;
	l->first->ant = NULL;
}

void LInsert(Livro* l, ItemLivro item) {
	l->last->prox = (BlockLivro*)malloc(sizeof(BlockLivro));
	l->last->prox->ant = l->last;
	l->last = l->last->prox;

	l->last->data.id = item.id;
	l->last->data.id_categoria = item.id_categoria;
	l->last->data.quantidade = item.quantidade;

	l->last->data.nome = new char[item.str.length() + 1];
	memcpy(l->last->data.nome, item.str.c_str(), item.str.length() + 1);

	l->last->prox = NULL;
}

void LRemove(Livro* l, ItemLivro item) {
	BlockLivro* aux, * tmp;

	if (l->first == l->last || l == NULL || l->first->prox == NULL) {
		printf("LISTA DE LIVROS VAZIA!\n");
		return;
	}

	aux = l->first;
	while (aux->prox != NULL) {
		if (aux->prox->data.id != item.id)
			aux = aux->prox;
		else {
			tmp = aux;
			aux = aux->prox;
			tmp->prox = aux->prox;
			aux->prox->ant = tmp;
			free(aux);
		}
	}
}

void Swap(BlockLivro* a, BlockLivro* b) {
	ItemLivro aux;
	aux = a->data;
	a->data = b->data;
	b->data = aux;
}

void printLivro(Livro* l) {
	BlockLivro* aux;

	cout << endl << "LIVROS" << endl << endl;
	cout << "ID\t" << "CAT.\t" << "QUANT.\t" << "NOME" << endl << endl;

	aux = l->first->prox;
	while (aux != NULL) {
		cout << "[" << aux->data.id << "]:\t[" << aux->data.id_categoria << "]\t[" << aux->data.quantidade << "]\t" <<aux->data.nome << endl;
		aux = aux->prox;
	}
}

void LImprimeLivroEstante(Livro *l) {
	BlockLivro* aux;

	cout << endl << "LIVROS" << endl << endl;
	cout << "ID\t" << "NOME" << endl << endl;

	aux = l->first->prox;
	while (aux != NULL) {
		cout << "[" << aux->data.id << "]:\t" << aux->data.nome << endl;
		aux = aux->prox;
	}
}

int sizeLivro(Livro *l) {
	BlockLivro* aux;
	int quant;

	aux = l->first->prox;
	while (aux != NULL) {
		quant++;
		aux = aux->prox;
	}
	return quant;
}