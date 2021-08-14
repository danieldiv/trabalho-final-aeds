#ifndef __LISTIMP__
#define __LISTIMP__
#include "Lista.hpp"
#include <iostream>

using namespace std;

template <typename T> List<T>::List() {
  this->TAM = 0;
  this->HEAD = NULL;
  this->TAIL = NULL;
}

template <typename T> int List<T>::size() const noexcept{
	return this->TAM; 
}

template <typename T> bool List<T>::isEmpty() const noexcept{
  return this->TAM == 0;
}

template <typename T> void List<T>::push(const T dado){
  if (this->isEmpty()){
    this->HEAD = new node<T>(dado);
    this->TAIL = HEAD;
    this->TAM++;
  } else {
    this->TAIL->prox = new node<T>(dado);
    TAIL->prox->ant = TAIL;
    TAIL = TAIL->prox;
    TAIL->prox = NULL;
    this->TAM++;
  }
}

template <typename T> void List<T>::pop(){
  if (!TAIL)
    return;
  node<T> *pNode = TAIL;
  TAIL = TAIL->ant;
  delete pNode;
  pNode = NULL;
  if (TAIL == NULL || HEAD == NULL){
    HEAD = NULL;
    TAIL = NULL;
  }
  this->TAM--;
}

template <typename T> List<T>::~List<T>(){
  while (HEAD != NULL) {
    this->pop();
  }
  HEAD = NULL;
  TAIL = NULL;
}
#endif


