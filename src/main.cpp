// #include "estruturas/Lista.hpp"
#include "lib/json.hpp"
#include "livro.hpp"

#include <string>
#include <fstream>
#include <iostream>

using json = nlohmann::json;

int menu();
void integrantes();
void readJson(Livro* L);
void imprimeJson(ItemLivro item);

int main() {
	int op;

	Livro L;

	readJson(&L);

	// do {
	// 	system("cls || clear");
	// 	op = menu();

	// 	switch (op) {
	// 	case 1:
	// 		integrantes();
	// 		break;
	// 	case 0:
	// 		cout << "O sistema sera finalizado." << endl;
	// 		exit(0);
	// 	default:
	// 		cout << "Opcao invalida!!" << endl;
	// 	}

	// 	cout << endl;
	// 	system("pause");
	// } while (op != 0);
	return 0;
}

void readJson(Livro* L) {
	FLVazia(L);
	ItemLivro item;
	string str;
	char* nome;

	json js;
	ifstream file("arquivo.json");
	file >> js;

	for (int i = 0; i < js["livro"].size(); i++) {
		json aux = js["livro"][i];

		item.id = aux["id"];
		item.id_categoria = aux["categoria"];
		item.str = aux["nome"];
		item.quantidade = aux["quantidade"];

		LInsert(L, item);
		quanLivro++;
	}
	LImprimeLivro(L);
}

int menu() {
	int op;

	cout << "======================" << endl;
	cout << "  BIBLIOTECA VIRTUAL" << endl;
	cout << "======================" << endl << endl;

	cout << "1 - Integrantes" << endl;
	// cout << "2 - Exibir json" << endl;
	cout << "0 - Sair" << endl << endl;

	cout << "Escolha uma opcao: ";
	cin >> op;

	return op;
}

void integrantes() {
	system("cls || clear");
	cout << "=====================" << endl;
	cout << "     INTEGRANTES     " << endl;
	cout << "=====================" << endl << endl;

	cout << "Daniel Alves Sanches" << endl;
	cout << "Julia Mello Lopes Gonçalves" << endl;
	cout << "Leonardo de Oliveica Campos" << endl;
	cout << "Lucas de Souza Gontijo" << endl;
}