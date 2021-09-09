#include "funcionario.hpp"

/*
	Funcao: imprime, imprime os dados do funcionario que chama o metodo
*/
void funcionario::imprime() {
	cout << "[" << id << "]:\t" << nome << "\t" << usuario << "\t" << senha << endl;
}