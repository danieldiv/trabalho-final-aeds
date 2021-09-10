#include "estante.hpp"

/*
	==========================
		CUSTO ESTANTE.CPP
	==========================

	CONSTANTE
*/

/*
	Funcao: imprime, imprime os dados da estante com os seus livros
	@param quant: mostra a quantidade de livros da estante
	@param aux: utilizado para imprimir ou nao os livros da estante
*/
void estante::imprime(int quant, bool aux) {
	cout << "Estante [" << id << "]:" << endl;
	cout << "Itens: " << quant << endl << endl;
	cout << "Conteudo da Estante: " << endl;
	if (aux)//1
		LImprimeLivroEstante(&l);//1
}