#include "main.hpp"

int main() {
	int op;

	Livro L;
	List<funcionario> LF;
	funcionario func;

	readJsonLivro(&L);
	readJsonFuncionario(&LF);

	login(&func, &LF);

	do {
		system("cls || clear");
		cout << "Bem vindo: " << func.nome << endl << endl;
		op = menu();

		switch (op) {
		case 1:
			integrantes();
			break;
		case 2:
			printAll(&L, &LF);
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

	cout << endl << "FUNCIONARIOS" << endl << endl;

	pLF = LF->HEAD;
	for (int i = 0; i < LF->size();i++) {
		pLF->dado.imprime();
		pLF = pLF->prox;
	}
}

void login(funcionario* func, List<funcionario>* LF) {
	string usuario, senha;
	bool aux;

	do {
		system("cls || clear");
		cout << "=====================" << endl;
		cout << "        LOGIN" << endl;
		cout << "=====================" << endl << endl;

		cout << "Usuario: ";
		cin >> usuario;
		cout << "Senha: ";
		cin >> senha;

		aux = realizarLogin(func, usuario, senha, LF);

		if (!aux)
			cout << "Usuario ou senha invalida!!" << endl << endl;
		else
			return;
		system("pause");
	} while (!aux);
}

bool realizarLogin(funcionario* func, string usuario, string senha, List<funcionario>* LF) {
	node<funcionario>* pLF;

	pLF = LF->HEAD;
	for (int i = 0; i < LF->size();i++) {
		if (pLF->dado.usuario.compare(usuario) == 0) {
			func->id = pLF->dado.id;
			func->nome = pLF->dado.nome;
			return true;
		}
		pLF = pLF->prox;
	}
	return false;
}

int menu() {
	int op;

	cout << "======================" << endl;
	cout << "  BIBLIOTECA VIRTUAL" << endl;
	cout << "======================" << endl << endl;

	cout << "1 - Integrantes" << endl;
	cout << "2 - Print All" << endl;
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