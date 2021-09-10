#include "menu.hpp"

/*
	Funcao: menuEstante
	@param LE: lista dinamica da estante
	@param FP: fila dinamica da pessoa
	@param L: lista dinamica do livro
*/
void menuEstante(List<estante>* LE, Fila<pessoa>* FP, Livro* L) {
	int option;
	do {
		// system("clear || cls");
		cout << "======================" << endl;
		cout << "     MENU ESTANTE" << endl;
		cout << "======================" << endl << endl;
		cout << "1 - Pegar    Livro" << endl;
		cout << "2 - Devolver Livro" << endl;
		cout << "3 - Novo     Livro para a Estante" << endl;
		cout << "4 - Mostrar  Livros" << endl;
		cout << "0 - Voltar" << endl;
		cout << endl << "Opcao: ";
		cin >> option;

		// system("clear || cls");

		switch (option) {
		case 1:
			pegarLivro(LE, FP, L);
			break;
		case 2:
			// devolverLivro(LE, FP);
			break;
		case 3:
			inserirNaEstante(L, LE);
			break;
		case 4:
			printEstante(LE, true);
			break;
		case 0:
			return;
		default:
			cout << "Opcao invalida!" << endl;
			break;
		}
		system("pause");
	} while (option != 0);
}

/*
	Funcao: pesquisarLivroEstante
	@param LE: lista dinamica da estante
*/
int pesquisarLivroEstante(List<estante>* LE) {
	// List<string> LS;
	BlockLivro* aux;
	node<estante>* pLE;
	char* temp = (char*)malloc(128);
	string procurado;
	string pesquisa;
	int n;

	cout << endl << "Qual livro deseja buscar: ";
	cin.ignore();
	getline(cin, pesquisa);

	pLE = LE->HEAD;
	for (int i = 0; i < LE->size();i++) {
		aux = pLE->dado.l.first->prox;
		while (aux != NULL) {
			n = sprintf(temp, aux->data.nome);
			procurado = temp;

			if (procurado.find(pesquisa) != string::npos) {
				return aux->data.id;
			}
			else {
				cout << "not found" << endl;
				return -1;
			}
			aux = aux->prox;
		}
		pLE = pLE->prox;
	}
	system("pause");
}

/*
	Funcao: printEstante
	@param LE: lista dinamica da estante
	@param aux: booleano para controle de exibicao
*/
void printEstante(List<estante>* LE, bool aux) {
	cout << "=====================" << endl;
	cout << "      ESTANTES" << endl;
	cout << "=====================" << endl << endl;

	node<estante>* pLE;
	pLE = LE->HEAD;

	for (int i = 0; i < LE->size();i++) {
		pLE->dado.imprime(sizeLivro(&pLE->dado.l), aux);
		cout << endl << "===============================" << endl << endl;
		pLE = pLE->prox;
	}
}

/*
	Funcao: pegarLivro
	@param LE: lista dinamica da estante
	@param FP: fila dinamica da pessoa
*/
void pegarLivro(List<estante>* LE, Fila<pessoa>* FP, Livro* L) {
	ItemPilha item;
	node<estante>* pLE;
	BlockLivro* temp;
	string nome;
	bool found = false;
	int idLivro, numEstante;

	printEstante(LE, false);

	do {
		cout << endl << "Selecione a estante ou '0' para sair: ";
		cin >> numEstante;

		if (numEstante == 0)
			return;

		pLE = LE->HEAD;
		for (int i = 0; i < LE->size();i++) {
			if (numEstante == pLE->dado.id) {
				found = true;
				break;
			}
			pLE = pLE->prox;
		}
		if (!found)
			cout << "Estante nao encontrada!" << endl;
	} while (!found);

	// system("cls || clear");
	found = false;

	cout << endl << "Estante " << numEstante << " selecionada!" << endl;
	LImprimeLivroEstante(&pLE->dado.l);

	do {
		cout << endl << "Escolha o ID do livro que deseja inserir ou '0' para sair: ";
		fflush(stdin);
		cin >> idLivro;

		if (idLivro == 0)
			return;

		temp = pLE->dado.l.first->prox;
		while (temp != NULL) {
			if (temp->data.id == idLivro && temp->data.controle) {
				found = true;
				temp->data.controle = false;
				break;
			}
			temp = temp->prox;
		}

		if (!found)
			cout << endl << "Livro nao encontrado ou nao disponivel!" << endl;
		else {

			item.val = temp->data.id;
			item.idEstante = numEstante;
			Push(&FP->HEAD->dado.livros, item);

			cout << endl << "Livro '" << LBusca(L, idLivro).nome << "' selecionado!" << endl << endl;
		}
	} while (!found);
	system("pause");
}

/*
	Funcao: inserirNaEstante
	@param L: lista dinamica do livro
	@param LE: lista dinamica da estante
*/
void inserirNaEstante(Livro* L, List<estante>* LE) {
	int idLivro, numEstante;
	bool found = false;
	BlockLivro* temp;
	node<estante>* pLE;

	// system("cls || clear");
	cout << "=======================" << endl;
	cout << " INSERIR LIVRO ESTANTE" << endl;
	cout << "=======================" << endl;

	printEstante(LE, false);

	do {
		cout << endl << "Selecione a estante ou '0' para sair: ";
		cin >> numEstante;

		if (numEstante == 0)
			return;

		pLE = LE->HEAD;
		for (int i = 0; i < LE->size();i++) {
			if (numEstante == pLE->dado.id) {
				found = true;
				break;
			}
			pLE = pLE->prox;
		}
		if (!found)
			cout << "Estante nao encontrada!" << endl;
	} while (!found);

	// system("cls || clear");
	found = false;

	cout << endl << "Estante " << numEstante << " selecionada!" << endl;
	printLivro(L);

	do {
		cout << endl << "Escolha o ID do livro que deseja inserir ou '0' para sair: ";
		fflush(stdin);
		cin >> idLivro;

		if (idLivro == 0)
			return;

		temp = L->first->prox;
		while (temp != NULL) {
			if (temp->data.id == idLivro) {
				found = true;
				temp->data.controle = true;
				break;
			}
			temp = temp->prox;
		}

		if (!found)
			cout << "Livro nao encontrado!" << endl;
		else {
			ItemLivro item;

			item.id = temp->data.id;
			item.nome = temp->data.nome;
			item.id_categoria = temp->data.id_categoria;
			item.controle = temp->data.controle;

			LInsert(&pLE->dado.l, item);
			cout << "Livro inserido!" << endl;
		}
	} while (!found);
	system("pause");
}

void retornarEstante(List<estante>* LE, PilhaLivro* p) {
	// node<estante>* pLE;
	// BlockLivro* aux;
	// pLE = LE->HEAD;

	// for (int i = 0; i < LE->size();i++) {
	// 	for (int j = 0; j < LE->size();j++) {
	// 		if (p->top->dado.idEstante == pLE->dado.id) {
	// 			aux = pLE->dado.l.first->prox;

	// 			while (aux != NULL) {
	// 				if (aux->data.id == p->top->dado.val)
	// 					aux->data.controle = true;
	// 				aux = aux->prox;
	// 			}
	// 		}
	// 		pLE = pLE->prox;
	// 	}
	// }
}