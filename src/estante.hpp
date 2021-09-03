#ifndef ESTANTE_HPP
#define ESTANTE_HPP

#include <string>
#include <iostream>
#include "livro.hpp"

using namespace std;

struct estante {
    int id;
	Livro l;

    void imprime(int quant);
	// void insereLivro(Livro l);

    estante() = default;
    estante(int id) : id(id) {}
};
#endif