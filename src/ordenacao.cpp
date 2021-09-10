#include "ordenacao.hpp"
/*
	==========================
		CUSTO ORDENACAO .CPP
	==========================

	6 + 2N + N + 4 + 8N + 2 + 1 = 13 + 11N
*/

/*
	Funcao: Initialize
	Custo computacional: 2
	@param v: lista de inteiros
	@param tam, tamanho da lista
*/
void Initialize(Vector *v, int tam) {    
    v->itens = (int *)malloc(tam * sizeof(int));
	v->swap = 0;
}

/*
	Funcao: Initialize
	Custo computacional: 1
	@param v: lista de inteiros
	@param tam, tamanho da lista
*/
void InsereValor(Vector *v, int id, int val) {
	v->itens[id] = val;
}

/*
	Funcao: Initialize
	Custo computacional: 3
	@param v: lista de inteiros
	@param tam, tamanho da lista
*/
void Swap(int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

/*
	Funcao: Initialize
	Custo computacional: 2 + 2N + N
	@param v: lista de inteiros
	@param tam, tamanho da lista
*/
void Imprime(Vector *v, int tam) {
	for(int i=0; i < tam; i++)
		printf("%d\t", v->itens[i]);
	printf("\n");
}

/*
	Funcao: Initialize
	Custo computacional: 4 + 8N + 2 + 1
	@param v: lista de inteiros
	@param tam, tamanho da lista
*/
void Partition(Vector *v, int p, int r, int *i, int *j) {
	int pivo;
	int idx = (p+r)/2;
	*i = p;
	*j = r;
	pivo = v->itens[idx];

	do{
		while(v->itens[*i] < pivo && *i < r)
			*i = *i + 1;
		while(v->itens[*j] > pivo && *j > p)
			*j = *j - 1;
		if(*i<=*j){
			Swap(&v->itens[*i], &v->itens[*j]);
			*i = *i + 1;
			*j = *j - 1;
			v->swap++;
		}

	}while(*i<=*j);
	
}

/*
	Funcao: Initialize
	@param v: lista de inteiros
	@param tam, tamanho da lista
*/
void QuickSort(Vector *v, int p, int r, int i, int j, int tam) {
	
	Partition(v, p, r, &i, &j);
	Imprime(v, tam);
	if(j > p)
		QuickSort(v, p, j, i, j, tam);
	if(i < r)
		QuickSort(v, i, r, i, j, tam);
}
