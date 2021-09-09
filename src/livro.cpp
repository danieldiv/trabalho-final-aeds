#include "livro.hpp"

/*
	Funcao: FLVazia
	@param: l: ponteiro de uma lista de livro para inicializar
*/
void FLVazia(Livro* l) {
	l->first = (BlockLivro*)malloc(sizeof(BlockLivro));
	l->last = l->first;
	l->first->prox = NULL;
	l->first->ant = NULL;
}

/*
	Funcao: LInsert
	@param l: ponteiro de uma lista de livro para inserir
	@param item: item que sera adicionado no livro
*/
void LInsert(Livro* l, ItemLivro item) {
	l->last->prox = (BlockLivro*)malloc(sizeof(BlockLivro));
	l->last->prox->ant = l->last;
	l->last = l->last->prox;

	if (item.str.length() == 0)
		l->last->data.nome = item.nome;

	else {
		l->last->data.nome = new char[item.str.length() + 1];
		memcpy(l->last->data.nome, item.str.c_str(), item.str.length() + 1);
	}

	l->last->data.id = item.id;
	l->last->data.id_categoria = item.id_categoria;
	l->last->data.controle = item.controle;

	l->last->prox = NULL;
}

/*
	Funcao: LRemove
	@param l: ponteiro de uma lista de livro para remover
	@param item: item que sera utilizar para procurar o id para a remoca
*/
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

/*
	Funcao: printLivro
	@param l: lista dinamica do livro para impressao
*/
void printLivro(Livro* l) {
	BlockLivro* aux;

	cout << endl << "LIVROS CADASTRADOS NO SISTEMA" << endl << endl;
	cout << "ID\t" << "CAT.\t" << "LIVROS" << endl << endl;

	aux = l->first->prox;
	while (aux != NULL) {
		cout << "[" << aux->data.id << "]:\t[" << aux->data.id_categoria << "]\t" << aux->data.nome << endl;
		aux = aux->prox;
	}
}

/*
	Funcao: LImprimeLivroEstante
	@param l: lista dinamica do livro para imrpessao sem categoria
*/
void LImprimeLivroEstante(Livro *l) {
	BlockLivro* aux;

	// cout << endl << "LIVROS" << endl << endl;
	cout << "ID\t" << "CTRL.\t" << "LIVROS" << endl << endl;

	aux = l->first->prox;
	while (aux != NULL) {
		cout << "[" << aux->data.id << "]:\t" << aux->data.controle << "\t" << aux->data.nome << endl;
		aux = aux->prox;
	}
}

/*
	Funcao: sizeLivro
	@param l: lista dinamica do livro para verificar o tamanho da lista
	@result: retorna um inteiro referente a quantidade de livros dentro da lista
*/
int sizeLivro(Livro *l) {
	BlockLivro* aux;
	int quant = 0;

	aux = l->first->prox;
	while (aux != NULL) {
		quant++;
		aux = aux->prox;
	}
	return quant;
}

/*
	Funcao: LBusca
	@param l: lista dinamica do livro para pesquisa do id
	@result: retorna o livro pesquisado pelo id ou um livro com -1 caso nao encontrado
*/
ItemLivro LBusca(Livro *L, int idLivro) {
	BlockLivro *temp;
	ItemLivro result;

	temp = L->first->prox;
	while (temp != NULL) {
		if (temp->data.id == idLivro) {
			result.id = idLivro;
			result.nome = temp->data.nome;
			return result;
		}
		temp = temp->prox;
	}

	result.id = -1;
	return result;
}