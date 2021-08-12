#ifndef __FILA__
#define __FILA__
#include "Lista.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

template <typename T> class Fila : public List<T>{
	public:
	  Fila();
	  void pop() override;
};
#include "Fila.cpp"
#endif
