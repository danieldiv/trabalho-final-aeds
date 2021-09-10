#ifndef ORDENACAO_HPP 
#define ORDENACAO_HPP

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Vector Vector;

struct Vector{
	int *itens;
	int tam;
	int swap;
};

void Initialize(Vector *v, int tam);
void InsereValor(Vector *v, int id, int val);
void Imprime(Vector *v, int tam);
void Swap(int *a, int *b);
void Partition(Vector *v, int p, int r, int *i, int *j);
void QuickSort(Vector *v, int p, int r, int i, int j, int tam);

#endif