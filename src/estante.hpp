/*
    este .hpp sera responsavel pela estrutura da estante que ira armazenar os livros
*/

#ifndef ESTANTE_HPP
#define ESTANTE_HPP

#include <string>
#include <iostream>
#include "livro.hpp"

using namespace std;

struct estante {
    int id;
	Livro l;

    void imprime(int quant, bool aux);

    estante() = default;
    estante(int id) : id(id) {}
};
#endif