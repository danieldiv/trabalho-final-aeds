#include "menu.hpp"

/*
	==========================
		CUSTO MENU BIBL. .CPP
	==========================

	4 + 5N : FUNCIONARIO
	47 + 4N: PESSOA
*/

/*
	Funcao: menuBiblioteca
	Custo computacional: 8
	@param L: lista dinamica do livros
	@param LF: lista dinamica do funcionarios
	@param LC: lista dinamica da categarias
	@param LE: lista dinamica da estantes
	@param FP: fila dinamica da pessoas
*/
void menuBiblioteca(Livro* L, List<funcionario>* LF, List<categorias>* LC, List<estante>* LE, Fila<pessoa>* FP) {
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
		cin >> option;//1
		switch (option) {
		case 1:
			menuLivro(L, LC, LE);//1
			break;
		case 2:
			menuEstante(LE, FP, L);//1
			break;
		case 3:
			menuFuncionario(LF);//1
			break;
		case 4:
			printAll(L, LF, LC, LE, FP);//1
			system("pause");
			break;
		case 5:
			entradaDePessoas(FP);//1
			system("pause");
			break;
		case 6:
			saidaDePessoas(FP, LE);//1
			system("pause");
			break;
		case 0:
			return;
		default:
			cout << "Opcao invalida!" << endl;
			system("pause");
		}
	} while (option != 0);//1
}

/*
	Funcao: realizarLogin
	Custo computacional: 2 + 2 + 2N + N + 4N/2 = (4 + 5N)
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
	cin >> usuario;//1
	cout << "Senha: ";
	cin >> senha;//1

	pLF = LF->HEAD;//1
	for (int i = 0; i < LF->size();i++) {//2 + 2N
		if (pLF->dado.usuario.compare(usuario) == 0) {//1
			if (pLF->dado.senha.compare(senha) == 0) {//1
				func->id = pLF->dado.id;//1
				func->nome = pLF->dado.nome;//1

				return true;
			}
		}
		pLF = pLF->prox;//1
	}
	return false;
}

/*
	Funcao: printAll
	@param L: lista dinamica do livros
	@param LF: lista dinamica do funcionarios
	@param LC: lista dinamica da categarias
	@param LE: lista dinamica da estantes
	@param FP: fila dinamica da pessoas
*/
void printAll(Livro* L, List<funcionario>* LF, List<categorias>* LC, List<estante>* LE, Fila<pessoa>* FP) {
	printLivro(L);
	printFuncionario(LF);
	printCategoria(LC);
	printEstante(LE, true);
	printPessoa(FP);
}

/*
	Funcao: InicializarBiblioteca
	Custo computacional: 42
	@param FP: fila dinamica de pessoa que sera inicializada com valore de 1 a 10
*/
void InicializarBiblioteca(Fila<pessoa>* FP) {
	for (int i = 0; i < 10; i++) {//2 + 4*10
		FP->push(i + 1);
		FPVazia(&FP->TAIL->dado.livros);
	}
}

/*
	Funcao: printPessoa
	Custo computacional: 1 + 2 + 2N + 2N = 3 + 4N
	@param FP: fila dinamica de pessoa
*/
void printPessoa(Fila<pessoa>* FP) {
	cout << "PESSOAS" << endl << endl;

	if (FP->size() == 0) {//1
		cout << "Nao possui leitores na biblioteca" << endl << endl;
		return;
	}

	node<pessoa>* pId;
	pId = FP->HEAD;//1

	for (int i = 0; i < FP->size(); i++) {//2 + 2N
		pId->dado.imprime();//N
		pId = pId->prox;//N
	}
	cout << endl << endl;
}

/*
	Funcao: entradaDePessoas
	Custo computacional: 2
	@param FP: fila dinamica de pessoa
*/
void entradaDePessoas(Fila<pessoa>* FP) {
	if (FP->size() < 10) {//1
		FP->push((FP->size() != 0) ? (FP->TAIL->dado.id + 1) : 1);//1
		FPVazia(&FP->TAIL->dado.livros);
		cout << "Uma pessoa entrou na biblioteca!!" << endl << endl;
	}
	else {
		cout << endl << "BIBLIOTECA LOTADA!!" << endl;
		cout << "Espere no lado de fora!" << endl << endl;
	}
}

/*
	Funcao: saidaDePessoas
	Custo computacional: 2
	@param FP: fila dinamica de pessoa
*/
void saidaDePessoas(Fila<pessoa>* FP, List<estante>* LE) {
	if (FP->size() == 0)//1
		cout << "Nao possui leitores na biblioteca" << endl << endl;
	else {
		retornarEstante(LE, &FP->HEAD->dado.livros);//1
		FP->pop();//1
		cout << "Uma pessoa saiu da biblioteca!!" << endl << endl;
	}
}
