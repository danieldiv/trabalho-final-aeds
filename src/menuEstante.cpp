#include "menu.hpp"

/*
	Funcao: menuEstante
	@param LE: lista dinamica da estante
*/
void menuEstante(List<estante> *LE) {

}

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
	cout << endl << "ESTANTES" << endl << endl;

	node<estante>* pLE;
	pLE = LE->HEAD;

	for (int i = 0; i < LE->size();i++) {
		pLE->dado.imprime(sizeLivro(&pLE->dado.l), aux);
		cout << endl << "===============================" << endl << endl;
		pLE = pLE->prox;
	}
}