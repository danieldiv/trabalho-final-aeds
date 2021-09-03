#ifndef PESSOA_HPP
#define PESSOA_HPP

int static quantPessoa = 0;

#include <string>
#include <iostream>
#include "PilhaLivro.hpp"

using namespace std;

struct pessoa {
	int id;
	PilhaLivro livros;

	void imprime();
	// void pegarLivro(int idLivro);
	// void devolverLivro(int idLivro);

	pessoa() = default;
	pessoa(int id) : id(id) {}
};
#endif