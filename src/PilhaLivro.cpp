#include "PilhaLivro.hpp"

/*
	==========================
		CUSTO PILHA LIVRO.CPP
	==========================

	3 + 4 + 6 + 1 + 1 + 2N + 1 + 1 + 2N + 3 + 3N = 20 + 7N
*/

/*
	Funcao: FPVazia
	Custo computacional: 3
	@param: p: ponteiro de uma pilha de livros para inicializar
*/
void FPVazia(PilhaLivro *p) {//3
	p->base = (BlockPilha *) malloc(sizeof(BlockPilha));
	p->top = p->base;
	p->base->prox = NULL;
}

/*
	Funcao: Push
	Custo computacional: 4
	@param p: ponteiro de uma pilha de livro para inserir
	@param d: item que sera adicionado na pilha do livro
*/
void Push(PilhaLivro *p, ItemPilha d) {//4
	BlockPilha *aux = (BlockPilha *) malloc(sizeof(BlockPilha));
	aux->dado = d;
	aux->prox = p->top;
	p->top = aux;
}

/*
	Funcao: Pop
	Custo computacional: 6
	@param p: ponteiro de uma pilha de livro para remover
	@param d: item que sera utilizado para procurar o id para a remover
*/
void Pop(PilhaLivro *p, ItemPilha *d) {
	BlockPilha *aux;

	if(p->base == p->top || p == NULL) {//2
		printf("[Erro]: PESSOA NAO POSSUI LIVROS!!\n");
		return;
	}

	aux = p->top;//1
	p->top = p->top->prox;//1
	d->val = aux->dado.val;//1
	free(aux);//1
}

/*
	Funcao: Pimprime
	Custo computacional: 1 + 1 + 2N
	@param p: pilha dinamica do livro para impressao
*/
void Pimprime(PilhaLivro *p) {
	BlockPilha *aux;

	aux = p->top;//1
	while(aux != p->base) {//1
		printf("\n%d", aux->dado.val);
		aux = aux->prox;//1
	}
}

/*
	Funcao: Pimprime
	Custo computacional: 1 + 1 + 2N
	@param p: pilha dinamica do livro para impressao
*/
void PimprimeLivroPessoa(PilhaLivro *p) {
	BlockPilha *aux;

	aux = p->top;//1
	while(aux != p->base) {//1
		cout << "ID: " << aux->dado.val << "\tESTANTE: " << aux->dado.idEstante << endl;
		aux = aux->prox;//1
	}
}

/*
	Funcao: sizeLivroPilha
	Custo computacional: 3 + 3N
	@param l: pilha dinamica do livro para impressao
	@result: retorna o tamanho da pilha de livros na pessoa
*/
int sizeLivroPilha(PilhaLivro *p) {
	BlockPilha *aux;//1
	int cont = 0;//1

	aux = p->top;//1
	while(aux != p->base) {//3N
		cont++;
		aux = aux->prox;
	}
	return cont;
}

