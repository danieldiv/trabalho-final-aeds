#include "menu.hpp"

int main() {
	int option;
	string *usuario, *senha;

	funcionario func;
	Livro L;

	List<funcionario> LF;
	List<categorias> LC;
	List<estante> LE;

	readJsonLivro(&L);
	readJsonFuncionario(&LF);
	readJsonCategoria(&LC);
	readJsonEstante(&LE);
	//pessoasNaBibioteca();
	//saidaDePessoas(int id);

	do {
        system("cls || clear");
		   cout << "======================" << endl;
        cout << "      BIBLIOTECA"    << endl;
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
            exit(0);
        default:
            cout << "Opcao invalida!!" << endl << endl;
            break;
        }
    } while (option != 0);

	return 0;
}

// void readJsonCategoria() {

// 	List<categorias> L;
// 	node<categorias> *pL = L->HEAD;
// 	json j;
//   	ifstream file("j.json");
//   	file >> j;

// 	for(long unsigned int i = 0; i <j["categorias"].size(); i++){
// 		json aux = j["categoias"][i];
// 		L.push({aux["id"], aux["nome"]});
// 	}
// }

/*
//função que ira permitir ou não a imlementação da pilha de pessoas na biblioteca
	void pessoasNaBiblioteca(){
		int cont = 0;
		if(cont <= 10){
			//add na pilha
			cont++;
		}else{
			cout << "\tBIBLIOTECA LOTADA!" << endl;
			cout << "Por favor espere lá fora ate alguem sair!"  << endl;
		}
	}

//inicializa a biblioteca cheia
		List<int>IdPessoas;
		node<int> *pId = L->HEAD;

		for(int i = 0; i < 10; i++){
			IdPessoas.push(i);
		}

//função que inicializa com a biblioteca cheia e vai se modificando a medida que alguem sai
	void pessoasNaBiBlioteca(){
		int cont = IdPessoas.size();
		if(cont <= 10){
			IdPessoas.push(rand%100);
			cont++;
		}else{
			cout << "\tBIBLIOTECA LOTADA!" << endl;
			cout << "Por favor espere lá fora ate alguem sair!"  << endl;
		}
	}
	void saidaDePessoas(int id){
		int aux;
		for(int i = 0; i < IdPessoas.size(); i++){
			x = IdPessoas->dado;
			pId = pId->prox;
			if(x == id){
				IdPessoas.pop();
			}
		}
	}	
*/
