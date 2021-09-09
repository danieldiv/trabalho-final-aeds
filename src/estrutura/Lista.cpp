#ifndef __LISTIMP__
#define __LISTIMP__
#include "Lista.hpp"
#include <iostream>

using namespace std;

/*
  Funcao: List, este metodo e utilizado para inicializacao
  @param T: sera um tipo de arquivo definido pela struct utilizada
*/
template <typename T> List<T>::List() {
  this->TAM = 0;
  this->HEAD = NULL;
  this->TAIL = NULL;
}

/*
  Funcao: size
  @param T: sera um tipo de arquivo definido pela struct utilizada
  @result: este metodo retorna a quantidade da estrutura passada
*/
template <typename T> int List<T>::size() const noexcept {
  return this->TAM;
}

/*
  Funcao: size, este metodo verifica se a estrutura esta vazia
  @param T: sera um tipo de arquivo definido pela struct utilizada
  @result: este metodo retorna o valor zero caso nao tenha dados na estrutura
*/
template <typename T> bool List<T>::isEmpty() const noexcept {
  return this->TAM == 0;
}

/*
  Funcao: push, este metodo ira inserir valores na estrutura com o tipo de arquivo definido pela struct
  @param T: sera um tipo de arquivo definido pela struct utilizada
  @param dado, valor que sera inserido na estrutura
*/
template <typename T> void List<T>::push(const T dado) {
  if (this->isEmpty()) {
    this->HEAD = new node<T>(dado);
    this->TAIL = HEAD;
    this->TAM++;
  }
  else {
    this->TAIL->prox = new node<T>(dado);
    TAIL->prox->ant = TAIL;
    TAIL = TAIL->prox;
    TAIL->prox = NULL;
    this->TAM++;
  }
}

/*
  Funcao: pop, este metodo ira excluir o valor de acordo com a estrutura
  @param T: sera um tipo de arquivo definido pela struct utilizada
*/
template <typename T> void List<T>::pop() {
  if (!TAIL)
    return;
  node<T>* pNode = TAIL;
  TAIL = TAIL->ant;
  delete pNode;
  pNode = NULL;
  if (TAIL == NULL || HEAD == NULL) {
    HEAD = NULL;
    TAIL = NULL;
  }
  this->TAM--;
}

/*
  Funcao: ~List, destrutor da funcao
  @param T: sera um tipo de arquivo definido pela struct utilizada
*/
template <typename T> List<T>::~List<T>() {
  while (HEAD != NULL) {
    this->pop();
  }
  HEAD = NULL;
  TAIL = NULL;
}
#endif


