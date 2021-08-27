#include "estante.hpp"

void estante::imprime() {
	cout << "[" << id << "]:" << endl;

	LImprimeLivroEstante(&l);
}