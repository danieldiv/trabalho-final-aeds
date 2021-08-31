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
