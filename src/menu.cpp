#include "menu.hpp"

void menuBiblioteca(Livro* L, List<funcionario>* LF, List<categorias>* LC, List<estante>* LE) {
	int option;
	do {
		system("clear || cls");
		cout << "======================" << endl;
		cout << "    MENU BIBLIOTECA" << endl;
		cout << "======================" << endl << endl;
		cout << "1 - Cadastrar Livro" << endl;
		cout << "2 - Editar    Livro" << endl;
		cout << "3 - Remover   Livro" << endl;
		cout << "4 - Pesquisar Livro" << endl;
		cout << "5 - Pesquisar Categoria" << endl;
		cout << "6 - Exibir Funcionarios" << endl;
		cout << "7 - Acessar Estante" << endl;
		cout << "8 - Imprimir Tudo" << endl;
		// implementar adição a fila; adição a biblioteca e remoção da biblioteca
		cout << "0 - Voltar" << endl;
		cout << endl << "Opcao: ";
		cin >> option;
		switch (option) {
		case 1:
			cadastrarLivro(L, LC);
			break;

		case 2:
			// editar livro
			break;

		case 3:
			// remover livro
			break;

		case 4:
			// pesquisar livro
			break;

		case 5:
			// pesquisar categoria
			break;

		case 6:
			// exibir funcionarios
			break;

		case 7:
			// acessar estante
			break;

		case 8:
			printAll(L, LF, LC, LE);
			break;

		case 0:
			cout << "Voltando..." << endl << endl;
			break;

		default:
			cout << "Opcao invalida!" << endl << endl;
			break;
		}
		system("pause");
	} while (option != 0);
}

void cadastrarLivro(Livro* L, List<categorias>* LC) {
	string nome;
	int quantidade;
	int categoria;
	bool aux = false;

	ItemLivro item;
	node<categorias>* pLC;

	system("cls || clear");
	cout << "=====================" << endl;
	cout << "    CADASTRO LIVRO" << endl;
	cout << "=====================" << endl << endl;

	cout << "Informe o nome do livro: ";
	fflush(stdin);
	getline(cin, nome);

	cout << "Informe a quantidade do livro: ";
	cin >> quantidade;

	cout << "CATEGORIAS" << endl << endl;

	pLC = LC->HEAD;
	for (int i = 0; i < LC->size();i++) {
		pLC->dado.imprime();
		pLC = pLC->prox;
	}

	do {
		cout << endl << "Escolha a categoria: ";
		cin >> categoria;

		pLC = LC->HEAD;
		for (int i = 0; i < LC->size();i++) {
			aux = (pLC->dado.buscarCat(categoria)) ? true : aux;
			pLC = pLC->prox;

			if (aux)
				break;
		}

		if (!aux)
			cout << "Categoria nao encontrada!!" << endl;
	} while (!aux);

	item.id_categoria = categoria;
	item.id = sizeLivro(L) + 1;
	item.str = nome;
	item.quantidade = quantidade;

	LInsert(L, item);
}

bool realizarLogin(funcionario* func, List<funcionario>* LF) {
	string usuario, senha;
	node<funcionario>* pLF;

	system("cls || clear");
	cout << "=====================" << endl;
	cout << "        LOGIN" << endl;
	cout << "=====================" << endl << endl;

	cout << "Usuario: ";
	cin >> usuario;
	cout << "Senha: ";
	cin >> senha;

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

void printAll(Livro* L, List<funcionario>* LF, List<categorias>* LC, List<estante>* LE) {
	LImprimeLivro(L);

	node<funcionario>* pLF;
	node<categorias>* pLC;
	node<estante>* pLE;

	int i;

	cout << endl << "FUNCIONARIOS" << endl << endl;

	pLF = LF->HEAD;
	for (i = 0; i < LF->size();i++) {
		pLF->dado.imprime();
		pLF = pLF->prox;
	}

	cout << endl << "CATEGORIAS" << endl << endl;

	pLC = LC->HEAD;
	for (i = 0; i < LC->size();i++) {
		pLC->dado.imprime();
		pLC = pLC->prox;
	}

	cout << endl << "ESTANTES" << endl << endl;

	pLE = LE->HEAD;
	for (i = 0; i < LE->size();i++) {
		pLE->dado.imprime(sizeLivro(&pLE->dado.l));
		cout << endl << "===============================" << endl << endl;
		pLE = pLE->prox;
	}
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
