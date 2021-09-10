#include "livro.hpp"

/*
	==========================
		CUSTO LIVRO.CPP
	==========================

	4 + 9 + 6 + 3N + 2 + 2N + 3 + 3N + 2 + 3N = 26 + 11N
*/

/*
	Funcao: FLVazia
	Custo computacional: 4
	@param: l: ponteiro de uma lista de livro para inicializar
*/
void FLVazia(Livro* l) {//4
	l->first = (BlockLivro*)malloc(sizeof(BlockLivro));
	l->last = l->first;
	l->first->prox = NULL;
	l->first->ant = NULL;
}

/*
	Funcao: LInsert
	Custo computacional: 9
	@param l: ponteiro de uma lista de livro para inserir
	@param item: item que sera adicionado no livro
*/
void LInsert(Livro* l, ItemLivro item) {//9
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
	Custo computacional: 3 + 1 + 1 + 1 + 6/2 = (6 + 3N) = 6 + 3N
	@param l: ponteiro de uma lista de livro para remover
	@param item: item que sera utilizado para procurar o id para a remover
*/
bool LRemove(Livro* l, ItemLivro item) {
	BlockLivro* aux, * tmp;
	if (l->first == l->last || l == NULL || l->first->prox == NULL) {//3
		printf("LISTA DE LIVROS VAZIA!\n");
		return false;
	}

	aux = l->first;//1
	while (aux->prox != NULL) {//1
		if (aux->prox->data.id != item.id)//1
			aux = aux->prox;//1
		else {
			tmp = aux;//1
			aux = aux->prox;//1
			tmp->prox = aux->prox;//1
			aux->prox->ant = tmp;//1
			free(aux);//1
			return true;
		}
	}
	return false;
}

/*
	Funcao: printLivro
	Custo computacional: 1 + 1 + 2N = 2 + 2N
	@param l: lista dinamica do livro para impressao
*/
void printLivro(Livro* l) {
	BlockLivro* aux;

	cout << endl << "LIVROS CADASTRADOS NO SISTEMA" << endl << endl;
	cout << "ID\t" << "CAT.\t" << "LIVROS" << endl << endl;

	aux = l->first->prox;//1
	while (aux != NULL) {//1
		cout << "[" << aux->data.id << "]:\t[" << aux->data.id_categoria << "]\t" << aux->data.nome << endl;
		aux = aux->prox;//1
	}
}

/*
	Funcao: LImprimeLivroEstante
	Custo computacional: 2 + 2N
	@param l: lista dinamica do livro para imrpessao sem categoria
*/
void LImprimeLivroEstante(Livro* l) {
	BlockLivro* aux;

	// cout << endl << "LIVROS" << endl << endl;
	cout << "ID\t" << "CTRL.\t" << "LIVROS" << endl << endl;

	aux = l->first->prox;//1
	while (aux != NULL) {//1
		cout << "[" << aux->data.id << "]:\t" << aux->data.controle << "\t" << aux->data.nome << endl;
		aux = aux->prox;
	}
}

/*
	Funcao: sizeLivro
	Custo computacional: 2 + 1 + 3N = 3 + 3N
	@param l: lista dinamica do livro para verificar o tamanho da lista
	@result: retorna um inteiro referente a quantidade de livros dentro da lista
*/
int sizeLivro(Livro* l) {
	BlockLivro* aux;
	int quant = 0;//1

	aux = l->first->prox;//1
	while (aux != NULL) {//3
		quant++;
		aux = aux->prox;
	}
	return quant;
}

/*
	Funcao: LBusca
	Custo computacional: 2 + N + N + 2N/2 = (2 + 3N)
	@param l: lista dinamica do livro para pesquisa do id
	@result: retorna o livro pesquisado pelo id ou um livro com -1 caso nao encontrado
*/
ItemLivro LBusca(Livro* L, int idLivro) {
	BlockLivro* temp;
	ItemLivro result;

	temp = L->first->prox;//1
	while (temp != NULL) {
		if (temp->data.id == idLivro) {//1
			result.id = idLivro;//1
			result.nome = temp->data.nome;//1
			return result;
		}
		temp = temp->prox;//1
	}

	result.id = -1;//1
	return result;
}