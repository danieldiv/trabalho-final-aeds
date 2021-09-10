#include "PilhaLivro.hpp"

/*
	Funcao: FPVazia
	@param: p: ponteiro de uma pilha de livros para inicializar
*/
void FPVazia(PilhaLivro *p) {
	p->base = (BlockPilha *) malloc(sizeof(BlockPilha));
	p->top = p->base;
	p->base->prox = NULL;
}

/*
	Funcao: Push
	@param p: ponteiro de uma pilha de livro para inserir
	@param d: item que sera adicionado na pilha do livro
*/
void Push(PilhaLivro *p, ItemPilha d) {
	BlockPilha *aux = (BlockPilha *) malloc(sizeof(BlockPilha));
	aux->dado = d;
	aux->prox = p->top;
	p->top = aux;
}

/*
	Funcao: Pop
	@param p: ponteiro de uma pilha de livro para remover
	@param d: item que sera utilizado para procurar o id para a remover
*/
void Pop(PilhaLivro *p, ItemPilha *d) {
	BlockPilha *aux;

	if(p->base == p->top || p == NULL) {
		printf("[Erro]: PESSOA NAO POSSUI LIVROS!!\n");
		return;
	}

	aux = p->top;
	p->top = p->top->prox;
	d->val = aux->dado.val;
	free(aux);
}

/*
	Funcao: Pimprime
	@param l: pilha dinamica do livro para impressao
*/
void Pimprime(PilhaLivro *p) {
	BlockPilha *aux;

	aux = p->top;
	while(aux != p->base) {
		printf("\n%d", aux->dado.val);
		aux = aux->prox;
	}
}

void PimprimeLivroPessoa(PilhaLivro *p) {
	BlockPilha *aux;

	aux = p->top;
	while(aux != p->base) {
		cout << "ID: " << aux->dado.val << "\tESTANTE: " << aux->dado.idEstante << endl;
		aux = aux->prox;
	}
}

/*
	Funcao: sizeLivroPilha
	@param l: pilha dinamica do livro para impressao
	@result: retorna o tamanho da pilha de livros na pessoa
*/
int sizeLivroPilha(PilhaLivro *p) {
	BlockPilha *aux;
	int cont = 0;

	aux = p->top;
	while(aux != p->base) {
		cont++;
		aux = aux->prox;
	}
	return cont;
}

