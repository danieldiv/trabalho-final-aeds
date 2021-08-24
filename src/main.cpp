#include "main.hpp"

int main() {
	int op;

	Livro L;
	List<funcionario> LF;

	readJsonLivro(&L);
	readJsonFuncionario(&LF);

	printAll(&L, &LF);

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

void printAll(Livro* L, List<funcionario>* LF) {
	LImprimeLivro(L);

	node<funcionario>* pLF;

	pLF = LF->HEAD;
	for (int i = 0; i < LF->size();i++) {
		pLF->dado.imprime(pLF->dado);
		pLF = pLF->prox;
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