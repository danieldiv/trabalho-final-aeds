#include "menu.hpp"

int main() {

	int option;
	string* usuario, * senha;

	funcionario func;
	Livro L;

	List<funcionario> LF;
	List<categorias> LC;
	List<estante> LE;

	readJsonLivro(&L);
	readJsonFuncionario(&LF);
	readJsonCategoria(&LC);
	readJsonEstante(&LE);

	InicializarBiblioteca();

	// return 0;
	//pessoasNaBibioteca();
	//saidaDePessoas(int id);

	// cout << "quant livro: " << sizeLivro(&L) << endl;
	// cout << "quant livro estantes: " << LE.size() << endl;

	// system("pause");

	do {
		system("cls || clear");
		cout << "======================" << endl;
		cout << "      BIBLIOTECA" << endl;
		cout << "======================" << endl << endl;
		cout << "1 - Login" << endl;
		cout << "2 - Informacoes de autoria" << endl;
		cout << "0 - Sair" << endl << endl;
		cout << "Opcao: ";

		cin >> option;
		switch (option) {
		case 1:
			if (realizarLogin(&func, &LF) == true)
				menuBiblioteca(&L, &LF, &LC, &LE);
			else
				cout << "Usuario ou senha invalida!!" << endl << endl;
			break;
		case 2:
			printAutores();
			break;
		case 0:
			cout << "O sistema sera finalizado" << endl;
			exit(0);
		default:
			cout << "Opcao invalida!!" << endl << endl;
			break;
		}
		system("pause");
	} while (option != 0);

	return 0;
}

//função que ira permitir ou não a imlementação da pilha de pessoas na biblioteca
void pessoasNaBiblioteca() {
	int cont = 0;
	if (cont <= 10) {
		//add na pilha
		cont++;
	}
}

// inicializa a biblioteca cheia/
void InicializarBiblioteca() {
	List<pessoa>IdPessoas;

	for (int i = 0; i < 10; i++) {
		IdPessoas.push(i + 1);
	}

	// imprimeLeitor(&IdPessoas);
	// saidaDePessoas(4, &IdPessoas);
	// imprimeLeitor(&IdPessoas);
}

void imprimeLeitor(List<pessoa>* leitor) {
	node<pessoa>* pId;

	pId = leitor->HEAD;
	for (int i = 0; i < leitor->size(); i++) {
		pId->dado.imprime();
		pId = pId->prox;
	}
	cout << endl;
}

//função que inicializa com a biblioteca cheia e vai se modificando a medida que alguem sai
// void pessoasNaBiBlioteca() {
// 	int cont = IdPessoas.size();
// 	if (cont <= 10) {
// 		IdPessoas.push(rand % 100);
// 		cont++;
// 	}
// 	else {
// 		cout << "\tBIBLIOTECA LOTADA!" << endl;
// 		cout << "Por favor espere lá fora ate alguem sair!" << endl;
// 	}
// }
void pessoasNaBiBlioteca(List<pessoa>* IdPessoas) {
		IdPessoas->push(IdPessoas->size() + 1);
		/*
			nao vai ter como ter limite, a nao ser que a remocao seja feita da forma statica, ou seja, exclui o ultimo que entrou
			utilizando a funcao do ist

			para excluir pessoas aleatorias, nao e possivel utilizar a funcao do List, e tambem nao foi possivel excluir trocando
			o endereco do prox, logo, para excluir, o id sera colocado em 0, nao sendo excluido realmente
		*/
}

// void saidaDePessoas(int id) {
// 	int aux;
// 	for (int i = 0; i < IdPessoas.size(); i++) {
// 		x = IdPessoas->dado;
// 		pId = pId->prox;
// 		if (x == id) {
// 			IdPessoas.pop();
// 		}
// 	}
// }

void saidaDePessoas(int id, List<pessoa>* IdPessoas) {
	int x;
	node<pessoa>* pId;

	pId = IdPessoas->HEAD;
	for (int i = 0; i < IdPessoas->size(); i++) {
		x = pId->dado.id;

		if (x == id) {
			pId->dado.pop();
		}

		pId = pId->prox;
	}
}