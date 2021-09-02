#include "estante.hpp"

void estante::imprime(int quant) {
	cout << "[" << id << "]:" << endl;
	cout << "Quantidade: " << quant << endl;

	LImprimeLivroEstante(&l);
}