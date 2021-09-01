#include "menu.hpp"

int main() {

	int option;
	string* usuario, * senha;

	funcionario func;
	Livro L;

	List<funcionario> LF;
	List<categorias> LC;
	List<estante> LE;

	readJsonLivro(&L);
	readJsonFuncionario(&LF);
	readJsonCategoria(&LC);
	readJsonEstante(&LE);
	//pessoasNaBibioteca();

	// cout << "quant livro: " << sizeLivro(&L) << endl;
	// cout << "quant livro estantes: " << LE.size() << endl;

	// system("pause");

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
			if (realizarLogin(&func, &LF) == true)
				menuBiblioteca(&L, &LF, &LC, &LE);
			else
				cout << "Usuario ou senha invalida!!" << endl << endl;
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
		system("pause");
	} while (option != 0);

	return 0;
}

//função que ira permitir ou não a imlementação da pilha de pessoas na biblioteca
void pessoasNaBiblioteca() {
	int cont = 0;
	if (cont <= 10) {
		//add na pilha
		cont++;
	}
	else {
		cout << "\tBIBLIOTECA LOTADA!" << endl;
		cout << "Por favor espere lá fora ate alguem sair!" << endl;
	}
}

