#include "menu.hpp"

/*
	Funcao: menuLivro
	@param L: lista dinamica do livros
	@param LC: lista dinamica da categarias
	@param LE: lista dinamica da estantes
*/
void menuLivro(Livro* L, List<categorias> *LC, List<estante> *LE) {
    int option;
    do {
		system("clear || cls");
		cout << "======================" << endl;
		cout << "      MENU LIVRO" << endl;
		cout << "======================" << endl << endl;
		cout << "1 - Cadastrar Livro" << endl;
		cout << "2 - Editar    Livro" << endl;
		cout << "3 - Excluir   Livro" << endl;
		cout << "4 - Inserir   Livro na Estante" << endl;
		cout << "5 - Imprimir  Livro" << endl;
		cout << "6 - Categoria Livro" << endl;
		cout << "0 - Voltar" << endl;
		cout << endl << "Opcao: ";
		cin >> option;

		system("clear || cls");

		switch (option) {
		case 1:
            cadastrarLivro(L, LC);
			break;
        case 2:
            editarLivro(L, LC, LE);
			break;
        case 3:
            // removerLivro(LC);
			break;
        case 4:
            inserirNaEstante(L, LE);
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
        system("pause");
    } while(option != 0);
}

/*
	Funcao: cadatrarLivro
	@param L: lista dinamica do livros
	@param LC: lista dinamica da categarias para cadatrar no livro
*/
void cadastrarLivro(Livro *L, List<categorias> *LC) {
	string nome;
	int categoria;
	bool aux = false;

	ItemLivro item;
	node<categorias>* pLC;

	system("cls || clear");
	cout << "=====================" << endl;
	cout << "    CADASTRO LIVRO" << endl;
	cout << "=====================" << endl << endl;

	cout << "Informe o nome do livro: ";
	cin.ignore();
	getline(cin, nome);
	cout << "Nome: " << nome << endl << endl;

	pLC = LC->HEAD;
	for (int i = 0; i < LC->size(); i++) {
		pLC->dado.imprime();
		pLC = pLC->prox;
	}

	do {
		cout << endl << "Escolha a categoria: ";
		fflush(stdin);
		cin >> categoria;

		pLC = LC->HEAD;
		for (int i = 0; i < LC->size();i++) {
			aux = pLC->dado.buscarCat(categoria) ? true : aux;
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

	LInsert(L, item);
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
	bool found = false;
	int counter = 0;
	BlockLivro* temp, * aux;

	// dados que serao trazidos do livro procurado
	int id;
	int id_categoria;
	string nome;
	// ======================

	ItemLivro item;
	node<categorias>* pLC;

	system("cls || clear");
	cout << "=====================" << endl;
	cout << "    EDITAR LIVRO" << endl;
	cout << "=====================" << endl;

	printLivro(L);

	cout << endl << endl << "Escolha o ID do livro que deseja editar ou '0' para sair: ";
	fflush(stdin);
	cin >> idLivro;

	system("cls || clear");

	if (idLivro == 0)
		return;

	temp = L->first->prox;
	while (temp != NULL) {
		if (temp->data.id == idLivro) {
			id = temp->data.id;
			id_categoria = temp->data.id_categoria;
			nome = temp->data.nome;
			found = true;
			break;
		}
		temp = temp->prox;
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
			cout << "3 - Remover Livro" << endl;
			cout << "0 - Voltar" << endl << endl;
			cout << "Opcao: ";
			cin >> option;

			system("cls || clear");

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

			case 3:
				// LRemove(L, temp->data);
				cout << "Livro removido";
				break;

			case 0:
				return;

			default:
				cout << "Opcao invalida!" << endl << endl;
				break;
			}
			if (option != 0)
				system("pause");
			system("cls || clear");
		} while (option != 0);
	}
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

	system("cls || clear");
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

	system("cls || clear");
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

/*
	Funcao: removerLivro
	@param L: lista dinamica do livros
	@param id: inteiro para excluir o livro
	
*/
void removerLivro(Livro* L, List<categorias>* LC);

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

