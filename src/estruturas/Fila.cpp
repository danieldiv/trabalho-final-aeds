#ifndef __FILAIMP__
#define __FILAIMP__
#include "Fila.hpp"

using namespace std;

template <typename T> Fila<T>::Fila() : List<T>() {}

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


