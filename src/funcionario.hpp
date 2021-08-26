#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <string>
#include <iostream>

using namespace std;

struct funcionario {
	int id;
	string nome;
	string usuario;
	string senha;

	void imprime();

	funcionario() = default;
	funcionario(int id, string nome) : id(id), nome(nome) {}
	funcionario(int id, string nome, string usuario, string senha)
		: id(id), nome(nome), usuario(usuario), senha(senha) {}

};
#endif