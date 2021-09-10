#include "menu.hpp"

/*
	Funcao: menuLivro
	@param L: lista dinamica do livros
	@param LC: lista dinamica da categarias
	@param LE: lista dinamica da estantes
*/
void menuLivro(Livro* L, List<categorias>* LC, List<estante>* LE) {
	int option;
	do {
		// system("clear || cls");
		cout << "======================" << endl;
		cout << "      MENU LIVRO" << endl;
		cout << "======================" << endl << endl;
		cout << "1 - Cadastrar Livro" << endl;
		cout << "2 - Editar    Livro" << endl;
		// cout << "3 - Excluir   Livro" << endl;
		
		cout << "5 - Imprimir  Livro" << endl;
		cout << "6 - Categoria Livro" << endl;
		cout << "0 - Voltar" << endl;
		cout << endl << "Opcao: ";
		cin >> option;

		// system("clear || cls");

		switch (option) {
		case 1:
			cadastrarLivro(L, LC);
			break;
		case 2:
			editarLivro(L, LC, LE);
			break;
		// case 3:
			// removerLivro(L);
		// 	break;
		case 4:
			// inserirNaEstante(L, LE);
			break;
		case 5:
			// funcao vem da estrutura livro
			printLivro(L);
			break;
		case 6:
			printCategoria(LC);
			break;
		case 0:
			return;
		default:
			cout << "Opcao invalida!" << endl;
			break;
		}
		// system("pause");
	} while (option != 0);//1
}

/*
	Funcao: cadatrarLivro
	@param L: lista dinamica do livros
	@param LC: lista dinamica da categarias para cadatrar no livro
*/
void cadastrarLivro(Livro* L, List<categorias>* LC) {
	string nome;
	int categoria;
	bool aux = false;//1

	ItemLivro item;
	node<categorias>* pLC;

	// system("cls || clear");
	cout << "=====================" << endl;
	cout << "    CADASTRO LIVRO" << endl;
	cout << "=====================" << endl << endl;

	cout << "Informe o nome do livro: ";
	cin.ignore();
	getline(cin, nome);//1
	cout << "Nome: " << nome << endl << endl;

	pLC = LC->HEAD;//1
	for (int i = 0; i < LC->size(); i++) {//2 + 2N
		pLC->dado.imprime();//1
		pLC = pLC->prox;//1
	}

	do {
		cout << endl << "Escolha a categoria: ";
		fflush(stdin);
		cin >> categoria;//1

		pLC = LC->HEAD;//1
		for (int i = 0; i < LC->size();i++) {//2 + 2N
			aux = pLC->dado.buscarCat(categoria) ? true : aux;//1
			pLC = pLC->prox;//1

			if (aux)//1//1
				break;
		}

		if (!aux)
			cout << "Categoria nao encontrada!!" << endl;

	} while (!aux);//1

	item.id_categoria = categoria;//1
	item.id = sizeLivro(L) > 0 ? L->last->data.id + 1 : 1;//1
	item.str = nome;//1

	LInsert(L, item);//1
}

/*
	Funcao: editarLivro
	@param L: lista dinamica do livros
	@param LC: lista dinamica da categarias para editar o livro
	@param LE: lista dinamica da estante que tambem sera atualizada na edicao
*/
void editarLivro(Livro* L, List<categorias>* LC, List<estante>* LE) {
	int idLivro;
	int option;
	bool found = false;//1
	int counter = 0;//1
	BlockLivro* temp, * aux;

	// dados que serao trazidos do livro procurado
	int id;
	int id_categoria;
	string nome;
	// ======================

	ItemLivro item;
	node<categorias>* pLC;

	// system("cls || clear");
	cout << "=====================" << endl;
	cout << "    EDITAR LIVRO" << endl;
	cout << "=====================" << endl;

	printLivro(L);

	cout << endl << endl << "Escolha o ID do livro que deseja editar ou '0' para sair: ";
	fflush(stdin);
	cin >> idLivro;//1

	// system("cls || clear");

	if (idLivro == 0)//1
		return;

	temp = L->first->prox;//1
	while (temp != NULL) {//1
		if (temp->data.id == idLivro) {//1
			id = temp->data.id;//1
			id_categoria = temp->data.id_categoria;//1
			nome = temp->data.nome;//1
			found = true;//1
			break;
		}
		temp = temp->prox;//1
	}

	if (!found)
		cout << endl << "Livro nao encontrado!!" << endl << endl;
	else {
		cout << endl << "Livro escolhido: " << temp->data.nome << endl << endl;
		do {
			counter = 0;
			cout << "O que deseja editar?" << endl << endl;
			cout << "1 - Nome" << endl;
			cout << "2 - Categoria" << endl;
			cout << "0 - Voltar" << endl << endl;
			cout << "Opcao: ";
			cin >> option;

			// system("cls || clear");

			switch (option) {
			case 1:
				cout << endl << "Nome atual: " << temp->data.nome << endl;
				cout << "Digite um novo nome: ";

				cin.ignore();
				getline(cin, nome);
				item.str = nome;

				temp->data.nome = new char[item.str.length() + 1];
				memcpy(temp->data.nome, item.str.c_str(), item.str.length() + 1);

				// ==============================================================

				node<estante>* pLE;
				pLE = LE->HEAD;

				for (int i = 0; i < LE->size();i++) {
					aux = pLE->dado.l.first->prox;
					while (aux != NULL) {
						if (aux->data.id == idLivro) {
							cout << "Encontrei o id" << endl;

							aux->data.nome = new char[item.str.length() + 1];
							memcpy(aux->data.nome, item.str.c_str(), item.str.length() + 1);
						}
						aux = aux->prox;
					}
					pLE = pLE->prox;
				}

				// ==============================================================

				cout << "Nome alterado!" << endl << endl;
				break;

			case 2:
				cout << endl << "Categoria atual: [" << temp->data.id_categoria << "]" << endl;
				cout << endl << "Categorias disponiveis:" << endl << endl;
				pLC = LC->HEAD;
				for (int i = 0; i < LC->size(); i++) {
					pLC->dado.imprime();
					pLC = pLC->prox;
					counter++;
				}

				cout << "Digite uma nova categoria: ";
				cin >> id_categoria;

				pLC = LC->HEAD;
				for (int i = 0; i < LC->size(); i++) {
					found = (pLC->dado.buscarCat(id_categoria)) ? true : false;
					if (found) {
						temp->data.id_categoria = id_categoria;
						cout << "Categoria alterada!" << endl;
						cout << "Nova categoria -> " << pLC->dado.nome << endl << endl;
						break;
					}
					pLC = pLC->prox;
				}
				if (!found) cout << "Categoria nao encontrada!" << endl << endl;
				break;

			case 0:
				return;

			default:
				cout << "Opcao invalida!" << endl << endl;
				break;
			}
			if (option != 0)
				system("pause");
			// system("cls || clear");
		} while (option != 0);
	}
}

/*
	Funcao: removerLivro
	@param L: lista dinamica do livros
	@param id: inteiro para excluir o livro

*/
// void removerLivro(Livro* L) {
// // system("cls || clear");
// 	cout << "=====================" << endl;
// 	cout << "    EXCLUIR LIVRO" << endl;
// 	cout << "=====================" << endl << endl;

// 	ItemLivro item;
// 	int id;
// 	bool temp = false, b = true;

// 	printLivro(L);

// 	cout << endl << "Informe o ID do livro para excluir ou '0' para sair: ";
// 	cin >> id;
// 	item.id = id;

// 	if (id == 0)
// 		return;

// 	if (item.id == L->last->data.id)
// 		b = !b;

// 	temp = LRemove(L, item, b);

// 	if (temp) {
// 		cout << "Livro excluido com sucesso!" << endl;
// 	}
// 	else
// 		cout << "Livro nao excluido ou nao encontrado" << endl;

// }

/*
	Funcao: printCategoria
	@param LC: lista dinamica da categorias
*/
void printCategoria(List<categorias>* LC) {
	cout << endl << "CATEGORIAS" << endl << endl;

	node<categorias>* pLC;
	pLC = LC->HEAD;
	for (int i = 0; i < LC->size();i++) {
		pLC->dado.imprime();
		pLC = pLC->prox;
	}
}

