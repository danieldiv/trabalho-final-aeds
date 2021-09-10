#include "pessoa.hpp"

/*
	Funcao: imprime, imprime os dados da pessoa que chama o metodo
*/
void pessoa::imprime() {
	cout << "[" << this->id << "]\t";

	if (sizeLivroPilha(&livros) > 0) {
		cout << endl;
		PimprimeLivroPessoa(&livros);

		cout << endl << endl;
	}
}