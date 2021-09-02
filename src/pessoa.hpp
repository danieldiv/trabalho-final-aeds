#ifndef PESSOA_HPP
#define PESSOA_HPP

int static quantPessoa = 0;

#include <string>
#include <iostream>

using namespace std;

struct pessoa {
	int id;

	void imprime();
	void pop();
	int getQuant();

	pessoa() = default;
	pessoa(int id) : id(id) {}
};
#endif