#include "categorias.hpp"

/*
	Funcao: imprime, imprime os dados da categoria que chama o metodo
*/
void categorias::imprime() {
	cout << "[" << id << "]:\t" << nome << endl;
}

/*
	Funcao: buscarCat
	@param idCat: valor utilizado para procurar uma categoria pelo id
	@result: retorna true caso tenha encontrado a categoria e false caso contrario
*/
bool categorias::buscarCat(int idCat) {
	if (idCat == getId())
		return true;
	return false;
}

/*
	Funcao: getId
	@result: retorna o id da categoria que chama o metodo
*/
int categorias::getId() {
	return id;
}