/*
    este .hpp sera responsavel pela estrutura das pessoas na biblioteca
*/

#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>
#include <iostream>
#include "PilhaLivro.hpp"

using namespace std;

struct pessoa {
	int id;
	PilhaLivro livros;

	void imprime();

	pessoa() = default;
	pessoa(int id) : id(id) {}
};
#endif