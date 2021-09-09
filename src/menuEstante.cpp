#include "menu.hpp"

/*
	Funcao: menuEstante
	@param LE: lista dinamica da estante
*/
void menuEstante(List<estante> *LE) {
	int option;
    do {
		system("clear || cls");
		cout << "======================" << endl;
		cout << "     MENU ESTANTE" << endl;
		cout << "======================" << endl << endl;
		cout << "1 - Pegar    Livro" << endl;
		cout << "2 - Devolver Livro" << endl;
		cout << "3 - Mostrar  Livros" << endl;
		cout << "0 - Voltar" << endl;
		cout << endl << "Opcao: ";
		cin >> option;

		system("clear || cls");

		switch (option) {
		case 1:
            // cadastrarLivro(L, LC);
			break;
        case 2:
            // editarLivro(L, LC, LE);
			break;
        case 3:
            printEstante(LE, true);
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
	Funcao: pesquisarLivroEstante
	@param LE: lista dinamica da estante
*/
void pesquisarLivroEstante(List<estante>* LE) {
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

            if (procurado.find(pesquisa) != string::npos)
                cout << "found" << endl;
            else
                cout << "not found" << endl;

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