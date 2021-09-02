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
	Fila<pessoa>IdPessoas;

	for (int i = 0; i < 10; i++) {
		IdPessoas.push(i + 1);
	}

<<<<<<< HEAD
//inicializa a biblioteca cheia
	void InicializarBiblioteca(){
		Fila<int>IdPessoas;
		node<int> *pId = L->HEAD;
=======
	// imprimeLeitor(&IdPessoas);
	// saidaDePessoas(4, &IdPessoas);
	// imprimeLeitor(&IdPessoas);
}
>>>>>>> dff92395b6a369affb1f4d36cae63de0ae27810b

void imprimeLeitor(Fila<pessoa>* leitor) {
	node<pessoa>* pId;

	pId = leitor->HEAD;
	for (int i = 0; i < leitor->size(); i++) {
		pId->dado.imprime();
		pId = pId->prox;
	}
	cout << endl;
}

void pessoasNaBiBlioteca(List<pessoa>* IdPessoas) {
	if(IdPessoas->size() == 10){
		IdPessoas->push(IdPessoas->size() + 1);
	}else{
		cout << "\tBIBLIOTECA LOTADA!!"<< endl;
		cout << "Espere no lado de fora!";
	}	
}

void saidaDePessoas(int id, Fila<pessoa>* IdPessoas) {
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
<<<<<<< HEAD
	void saidaDePessoas(int id){
		IdPessoas.pop();
	}	
=======
}
>>>>>>> dff92395b6a369affb1f4d36cae63de0ae27810b
