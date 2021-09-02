#include "pessoa.hpp"

void pessoa::imprime() {
	// if (this->id != 0)
		cout << "[" << this->id << "]\t";
}

void pessoa::pop() {
	this->id = 0;
}

int pessoa::getQuant() {
	return quantPessoa;
}