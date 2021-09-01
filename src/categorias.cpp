#include "categorias.hpp"

void categorias::imprime() {
	cout << "[" << id << "]:\t" << nome << endl;
}

bool categorias::buscarCat(int idCat) {
	if (idCat == getId())
		return true;
	return false;
}

int categorias::getId() {
	return id;
}