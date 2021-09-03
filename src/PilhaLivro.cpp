#include "PilhaLivro.hpp"

void FPVazia(PilhaLivro *p) {
	p->base = (BlockPilha *) malloc(sizeof(BlockPilha));
	p->top = p->base;
	p->base->prox = NULL;
}

void Push(PilhaLivro *p, ItemPilha d) {
	BlockPilha *aux = (BlockPilha *) malloc(sizeof(BlockPilha));
	aux->dado = d;
	aux->prox = p->top;
	p->top = aux;
}

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

void Pimprime(PilhaLivro *p) {
	BlockPilha *aux;

	aux = p->top;
	while(aux != p->base) {
		printf("\n%d", aux->dado.val);
		aux = aux->prox;
	}
}