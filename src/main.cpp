#include "menu.hpp"

int main() {
	int option;
	string* usuario, * senha;

	funcionario func;
	Livro L;

	List<funcionario> LF;
	List<categorias> LC;
	List<estante> LE;
	Fila<pessoa> FP;

	readJsonLivro(&L);//1
	readJsonFuncionario(&LF);//1
	readJsonCategoria(&LC);//1
	readJsonEstante(&LE, &L);//2

	do {
		// system("cls || clear");
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
				InicializarBiblioteca(&FP);
				menuBiblioteca(&L, &LF, &LC, &LE, &FP);
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
			cout << "O sistema foi finalizado!" << endl;
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
	// system("cls || clear");
	cout << "=====================" << endl;
	cout << "     INTEGRANTES     " << endl;
	cout << "=====================" << endl << endl;

	cout << "Daniel Alves Sanches         (3P - Comp.)" << endl;
	cout << "Julia Mello Lopes Goncalves  (3P - Comp.)" << endl;
	cout << "Leonardo de Oliveira Campos  (3P - Comp.)" << endl;
	cout << "Lucas de Souza Gontijo       (3P - Comp.)" << endl << endl;
}
