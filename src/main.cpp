#include "Lista.hpp"
#include "json.hpp"
#include "livro.hpp"
#include "funcionario.hpp"

#include <string>
#include <fstream>
#include <iostream>

using json = nlohmann::json;

int menu();
void integrantes();
void readJson(Livro* L);
void imprimeJson(ItemLivro item);
void teste(Livro* L, List<funcionario>* LF);

int main() {
	int op;

	cout << "teste" << endl;
	cout << (int) 'A' << endl;
	cout << (int) 'Z' << endl;

	Livro L;

	readJson(&L);
	system("pause");

	do {
		system("cls || clear");
		op = menu();

		switch (op) {
		case 1:
			integrantes();
			break;
		case 0:
			cout << "O sistema sera finalizado." << endl;
			exit(0);
		default:
			cout << "Opcao invalida!!" << endl;
		}

		cout << endl;
		system("pause");
	} while (op != 0);
	return 0;
}

void teste(Livro* L, List<funcionario>* LF) {
	node<funcionario>* pLF;
	cout << "teste"<<endl;
	pLF = LF->HEAD;
	for (int i = 0; i < LF->size();i++) {
		cout << pLF->dado.id << " " << pLF->dado.nome << " " << pLF->dado.usuario << " " << pLF->dado.senha << endl;

		pLF = pLF->prox;
	}
}

void readJson(Livro* L) {
	FLVazia(L);
	ItemLivro item;

	List<funcionario> LF;
	node<funcionario>* pLF;

	string str;
	char* nome;
	int i;

	json js;
	ifstream file("arquivo.json");
	file >> js;

	for (i = 0; i < js["livro"].size(); i++) {
		json aux = js["livro"][i];

		item.id = aux["id"];
		item.id_categoria = aux["categoria"];
		item.str = aux["nome"];
		item.quantidade = aux["quantidade"];

		LInsert(L, item);
		quanLivro++;
	}
	LImprimeLivro(L);

	for (i = 0; i < js["funcionario"].size(); i++) {
		json aux = js["funcionario"][i];

		LF.push({ aux["id"], aux["nome"], aux["usuario"], aux["senha"] });
	}

	pLF = LF.HEAD;
	teste(L, &LF);
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