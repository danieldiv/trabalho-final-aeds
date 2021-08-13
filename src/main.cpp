#include "main.hpp"
<<<<<<< HEAD
#include "Lista.hpp"
#include "json.hpp"

#include <string>
#include <fstream>

using namespace std;
using json = nlohmann::json;

struct produto {
	int cod;
	string nome;
	int quant;

	produto() = default;
	produto(int codB, string nomeB, int quantB)
		: cod(codB), nome(nomeB), quant(quantB) {}
};

void readJson();

int main() {
	// int op;

	readJson();

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
=======
#include "json.hpp"

int main() {
	int op;
	//json j;
	//ifstream file("j.json");
	//file >> j;
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
>>>>>>> d6e2ebd085fcf9f8f0f46462e36c5a533f802ee1

	return 0;
}

void readJson() {
	int i;
	List<produto> L1;
	node<produto>* pL1;

	json j;
	ifstream file("livros.json");
	file >> j;

	for (i = 0; i < j["produto"].size(); i++) {
		json aux = j["produto"][i];
		L1.push({ aux["codigo"], aux["nome"], aux["quantidade"] });
	}

	pL1 = L1.HEAD;
	for(i = 0; i < L1.size(); i++){
		cout << pL1->dado.cod << " - ";
		cout << pL1->dado.nome << " - ";
		cout << pL1->dado.quant << endl;

		pL1 = pL1->prox;
	}
}

int menu() {
	int op;

	cout << "======================" << endl;
	cout << "  BIBLIOTECA VIRTUAL" << endl;
	cout << "======================" << endl << endl;

	cout << "1 - Integrantes" << endl;
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