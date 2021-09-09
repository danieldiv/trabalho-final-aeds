#ifndef __FILAIMP__
#define __FILAIMP__
#include "Fila.hpp"

using namespace std;

/*
	Funcao: Fila, metodo responsavel pela inicializacao da Fila, que extende da inicializacao utilizada no List
	@param T: sera um tipo de arquivo definido pela struct utilizada
*/
template <typename T> Fila<T>::Fila() : List<T>() {}

/*
	Funcao: pop, metodo responsavel pela exclusao de valores da Fila, que extende do pop utilizada no List
	@param T: sera um tipo de arquivo definido pela struct utilizada
*/
template <typename T> void Fila<T>::pop(){
	if (!this->HEAD)
	    return;
    node<T> *pNode = this->HEAD;
    this->HEAD = this->HEAD->prox;
	delete pNode;
	pNode = NULL;
	this->TAM--;
}
#endif


