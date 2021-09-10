#include "funcionario.hpp"

/*
	=========================
	  CUSTO FUNCIONARIO.CPP
	=========================

	CONSTANTE
*/

/*
	Funcao: imprime, imprime os dados do funcionario que chama o metodo
*/
void funcionario::imprime() {
	cout << "[" << id << "]:\t" << nome << "\t" << usuario << "\t" << senha << endl;
}