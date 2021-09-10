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
		// system("pause");
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
	char* temp = (char*)malloc(128);//1
	string procurado;
	string pesquisa;
	int n;

	cout << endl << "Qual livro deseja buscar: ";
	cin.ignore();
	getline(cin, pesquisa);//1

	pLE = LE->HEAD;//1
	for (int i = 0; i < LE->size();i++) {//2 + 2N
		aux = pLE->dado.l.first->prox;//1
		while (aux != NULL) {//1
			n = sprintf(temp, aux->data.nome);//1
			procurado = temp;//1

			if (procurado.find(pesquisa) != string::npos) {//1
				return aux->data.id;//1
			}
			else {
				cout << "not found" << endl;
				return -1;
			}
			aux = aux->prox;//1
		}
		pLE = pLE->prox;//1
	}
	// system("pause");
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
	pLE = LE->HEAD;//1

	for (int i = 0; i < LE->size();i++) {//2 + 2N
		pLE->dado.imprime(sizeLivro(&pLE->dado.l), aux);//1
		cout << endl << "===============================" << endl << endl;
		pLE = pLE->prox;//1
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
	bool found = false;//1
	int idLivro, numEstante;

	printEstante(LE, false);

	do {
		cout << endl << "Selecione a estante ou '0' para sair: ";
		cin >> numEstante;

		if (numEstante == 0)//1
			return;

		pLE = LE->HEAD;//1
		for (int i = 0; i < LE->size();i++) {//2 + 2N
			if (numEstante == pLE->dado.id) {//1
				found = true;
				break;
			}
			pLE = pLE->prox;//1
		}
		if (!found)//1
			cout << "Estante nao encontrada!" << endl;
	} while (!found);//1

	// system("cls || clear");
	found = false;//1

	cout << endl << "Estante " << numEstante << " selecionada!" << endl;
	LImprimeLivroEstante(&pLE->dado.l);//1

	do {
		cout << endl << "Escolha o ID do livro que deseja pegar ou '0' para sair: ";
		fflush(stdin);
		cin >> idLivro;//1

		if (idLivro == 0)//1
			return;

		temp = pLE->dado.l.first->prox;//1
		while (temp != NULL) {//1
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
	// system("pause");
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
		cin >> numEstante;//1

		if (numEstante == 0)//1
			return;

		pLE = LE->HEAD;//1
		for (int i = 0; i < LE->size();i++) {//2 + 2N
			if (numEstante == pLE->dado.id) {//1
				found = true;//1
				break;
			}
			pLE = pLE->prox;//1
		}
		if (!found)//1
			cout << "Estante nao encontrada!" << endl;
	} while (!found);//1

	// system("cls || clear");
	found = false;//1

	cout << endl << "Estante " << numEstante << " selecionada!" << endl;
	printLivro(L);//1

	do {
		cout << endl << "Escolha o ID do livro que deseja inserir ou '0' para sair: ";
		fflush(stdin);
		cin >> idLivro;//1

		if (idLivro == 0)//1
			return;

		temp = L->first->prox;//1
		while (temp != NULL) {//1
			if (temp->data.id == idLivro) {//1
				found = true;//1
				temp->data.controle = true;//1
				break;
			}
			temp = temp->prox;//1
		}

		if (!found)//1
			cout << "Livro nao encontrado!" << endl;
		else {
			ItemLivro item;

			item.id = temp->data.id;//1
			item.nome = temp->data.nome;//1
			item.id_categoria = temp->data.id_categoria;//1
			item.controle = temp->data.controle;//1

			LInsert(&pLE->dado.l, item);//1
			cout << "Livro inserido!" << endl;
		}
	} while (!found);
	// system("pause");
}

void retornarEstante(List<estante>* LE, PilhaLivro* p) {
	node<estante>* pLE;
	BlockLivro* aux;
	ItemPilha item;
	
	pLE = LE->HEAD;
	aux = pLE->dado.l.first->prox;

	for (int i = 0; i < LE->size(); i++) {
		if (p->top->dado.idEstante == pLE->dado.id) {
			while (aux != NULL) {
				cout << aux->data.nome << endl;
				// if (sizeLivroPilha(p) == 0)
				// 	return;
				
				// Pop(p, &item);
				
				if (aux->data.id == item.val)
					aux->data.controle = true;
				aux = aux->prox;
			}
		}
		pLE = pLE->prox;
	}
}