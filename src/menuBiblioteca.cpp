#include "menu.hpp"

/*
	Funcao: menuBiblioteca
	@param L: lista dinamica do livros
	@param LF: lista dinamica do funcionarios
	@param LC: lista dinamica da categarias
	@param LE: lista dinamica da estantes
	@param LP: lista dinamica da pessoas
*/
void menuBiblioteca(Livro* L, List<funcionario>* LF, List<categorias>* LC, List<estante>* LE, List<pessoa>* LP) {
	int option;
	do {
		system("clear || cls");
		cout << "======================" << endl;
		cout << "    MENU BIBLIOTECA" << endl;
		cout << "======================" << endl << endl;
		cout << "1 - Opcoes de Livro" << endl;
		cout << "2 - Opcoes de Estante" << endl;
		cout << "3 - Opcoes de Funcionario" << endl;
		cout << "4 - Imprimir Tudo" << endl;

		cout << "5 - Simular entrada de pessoa" << endl;
		cout << "6 - Simular saida de pessoa" << endl << endl;

		cout << "0 - Voltar" << endl;
		cout << endl << "Opcao: ";
		cin >> option;
		switch (option) {
		case 1:
			menuLivro(L, LC, LE);
			break;
		case 2:
			menuEstante(LE);
			break;
		case 3:
			menuFuncionario(LF);
			break;
		case 4:
			printAll(L, LF, LC, LE, LP);
			system("pause");
			break;
		case 5:
			entradaDePessoas(LP);
			system("pause");
			break;
		case 6:
			saidaDePessoas(LP);
			system("pause");
			break;
		case 0:
			return;
		default:
			cout << "Opcao invalida!" << endl;
			system("pause");
		}
	} while(option != 0);
}

/*
	Funcao: realizarLogin
	@param func: funcionario que sera passado para validacao
	@param LF: lista dinamica do funcionarios
	@result: retorna true caso o usuario e senha seja correto e falso caso contrario
*/
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

/*
	Funcao: printAll
	@param L: lista dinamica do livros
	@param LF: lista dinamica do funcionarios
	@param LC: lista dinamica da categarias
	@param LE: lista dinamica da estantes
	@param LP: lista dinamica da pessoas
*/
void printAll(Livro* L, List<funcionario>* LF, List<categorias>* LC, List<estante>* LE, List<pessoa>* LP) {
	printLivro(L);
	printFuncionario(LF);
	printCategoria(LC);
	printEstante(LE, true);
	printPessoa(LP);
}

/*
	Funcao: InicializarBiblioteca
	@param LP: lista dinamica de pessoa que sera inicializada com valore de 1 a 10
*/
void InicializarBiblioteca(List<pessoa>* LP) {
	for (int i = 0; i < 10; i++) {
		LP->push(i + 1);
	}
}

/*
	Funcao: printPessoa
	@param LP: lista dinamica de pessoa
*/
void printPessoa(List<pessoa>* LP) {
	cout << "PESSOAS" << endl << endl;

	if (LP->size() == 0) {
		cout << "Nao possui leitores na biblioteca" << endl << endl;
		return;
	}

	node<pessoa>* pId;
	pId = LP->HEAD;

	for (int i = 0; i < LP->size(); i++) {
		pId->dado.imprime();
		pId = pId->prox;
	}
	cout << endl << endl;
}

void entradaDePessoas(List<pessoa>* IdPessoas) {
	if (IdPessoas->size() < 10) {
		IdPessoas->push((IdPessoas->size() != 0) ? (IdPessoas->TAIL->dado.id + 1) : 1);
		cout << "Uma pessoa entrou na biblioteca!!" << endl << endl;
	}
	else {
		cout << endl << "BIBLIOTECA LOTADA!!" << endl;
		cout << "Espere no lado de fora!" << endl << endl;
	}
}

void saidaDePessoas(List<pessoa>* IdPessoas) {
	if (IdPessoas->size() == 0)
		cout << "Nao possui leitores na biblioteca" << endl << endl;
	else {
		IdPessoas->pop();
		cout << "Uma pessoa saiu da biblioteca!!" << endl << endl;
	}
}

void adicionarLivroPessoa(List<estante>* LE, List<pessoa>* LP) {
	// int id;

	// printEstante(LE, true);

	// cout << "Escolha: " << endl;
	// cin >> id;

	// // LE->push(id);
	// printEstante(LE, false);
	// system("pause");

	// cout << "Tenha uma boa leitura!" << endl;
	// system("pause");
}