#include "main.hpp"

// using json = nlohmann::json;

int main() {
	int op;

	funcionario func;
	Livro L;

	List<funcionario> LF;
	List<categorias> LC;
	List<estante> LE;

	readJsonLivro(&L);
	readJsonFuncionario(&LF);
	readJsonCategoria(&LC);
	readJsonEstante(&LE);

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
			printAll(&L, &LF, &LC, &LE);
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

// void readJsonCategoria() {

// 	List<categorias> L;
// 	node<categorias> *pL = L->HEAD;
// 	json j;
//   	ifstream file("j.json");
//   	file >> j;

// 	for(long unsigned int i = 0; i <j["categorias"].size(); i++){
// 		json aux = j["categoias"][i];
// 		L.push({aux["id"], aux["nome"]});
// 	}
// }

void printAll(Livro* L, List<funcionario>* LF, List<categorias>* LC, List<estante>* LE) {
	LImprimeLivro(L);

	node<funcionario>* pLF;
	node<categorias>* pLC;
	node<estante>* pLE;

	cout << endl << "FUNCIONARIOS" << endl << endl;

	pLF = LF->HEAD;
	for (int i = 0; i < LF->size();i++) {
		pLF->dado.imprime();
		pLF = pLF->prox;
	}

	cout << endl << "CATEGORIAS" << endl << endl;

	pLC = LC->HEAD;
	for (int i = 0; i < LC->size();i++) {
		pLC->dado.imprime();
		pLC = pLC->prox;
	}

	cout << endl << "ESTANTES" << endl << endl;

	pLE = LE->HEAD;
	for (int i = 0; i < LE->size();i++) {
		pLE->dado.imprime();
		cout << endl << "===============================" << endl << endl;
		pLE = pLE->prox;
	}
}

void login(funcionario* func, List<funcionario>* LF) {
	string usuario, senha, op;
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

		if (!aux) {
			cout << "Usuario ou senha invalida!!" << endl << endl;
			cout << "Tentar novamente? (S / N): ";
			cin >> op;

			if (op.compare("N") == 0)
				exit(0);
		} else
			return;
		system("pause");
	} while (!aux);
}

bool realizarLogin(funcionario* func, string usuario, string senha, List<funcionario>* LF) {
	node<funcionario>* pLF;

	pLF = LF->HEAD;
	for (int i = 0; i < LF->size();i++) {
		if (pLF->dado.usuario.compare(usuario) == 0) {
			if (pLF->dado.senha.compare(senha) == 0) {
				func->id = pLF->dado.id;
				func->nome = pLF->dado.nome;

				return true;
			}
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