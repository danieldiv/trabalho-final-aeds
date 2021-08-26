#include "funcionario.hpp"

void funcionario::imprime() {
	cout << "[" << id << "]:\t" << nome << "\t" << usuario << "\t" << senha << endl;
}