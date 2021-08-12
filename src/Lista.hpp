#ifndef __LIST__
#define __LIST__
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

template <typename P> struct node{
  P dado;
  node<P> *ant;
  node<P> *prox;
  node() = default;
  node(const P dado) : dado(dado), ant(NULL), prox(NULL){}
};

template <typename T> class List{
	protected:
	  int TAM;
	public:
	  node<T> *TAIL;
	  node<T> *HEAD;
	  virtual void push(const T dado);
	  virtual void pop();
	  int size() const noexcept;
	  bool isEmpty()const noexcept;
	  List();
	  ~List();
};
#include "Lista.cpp"
#endif
