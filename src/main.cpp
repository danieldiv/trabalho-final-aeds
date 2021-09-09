#include "menu.hpp"

int main() {
	char* tmp = (char*)malloc(128);
	int n = sprintf(tmp, "daniel");

	string s2 = tmp;

	string teste = "iel";

	if (s2.find(teste) != string::npos) {
		cout << "found" << endl;
	}
	else cout << "not found" << endl;

	return 0;

	int option;
	string* usuario, * senha;

	funcionario func;
	Livro L;

	List<funcionario> LF;
	List<categorias> LC;
	List<estante> LE;
	List<pessoa> LP;

	readJsonLivro(&L);
	readJsonFuncionario(&LF);
	readJsonCategoria(&LC);
	readJsonEstante(&LE, &L);

	do {
		system("cls || clear");
		cout << "======================" << endl;
		cout << "      BIBLIOTECA" << endl;
		cout << "======================" << endl << endl;
		cout << "1 - Login" << endl;
		cout << "2 - Informacoes de autoria" << endl;
		cout << "0 - Sair" << endl << endl;
		cout << "Opcao: ";

		cin >> option;
		switch (option) {
		case 1:
			if (realizarLogin(&func, &LF) == true) {
				InicializarBiblioteca(&LP);
				menuBiblioteca(&L, &LF, &LC, &LE, &LP);
			}
			else {
				cout << "Usuario ou senha invalida!!" << endl << endl;
				system("pause");
			}
			break;
		case 2:
			printAutores();
			break;
		case 0:
			cout << "O sistema sera finalizado" << endl;
			exit(0);
		default:
			cout << "Opcao invalida!!" << endl << endl;
			break;
		}
		if (option != 1)
			system("pause");
	} while (option != 0);

	return 0;
}

void printAutores() {
	system("cls || clear");
	cout << "=====================" << endl;
	cout << "     INTEGRANTES     " << endl;
	cout << "=====================" << endl << endl;

	cout << "Daniel Alves Sanches         (3P - Comp.)" << endl;
	cout << "Julia Mello Lopes Goncalves  (3P - Comp.)" << endl;
	cout << "Leonardo de Oliveira Campos  (3P - Comp.)" << endl;
	cout << "Lucas de Souza Gontijo       (3P - Comp.)" << endl << endl;
}
