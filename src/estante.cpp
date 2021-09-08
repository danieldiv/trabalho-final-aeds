#include "estante.hpp"

void estante::imprime(int quant, bool aux) {
	cout << "[" << id << "]:" << endl;
	cout << "Quantidade: " << quant << endl;

	if (aux)
		LImprimeLivroEstante(&l);
}