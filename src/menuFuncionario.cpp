#include "menu.hpp"

/*
	Funcao: menuFuncionario
	@param LF: lista dinamica de funcionario
*/
void menuFuncionario(List<funcionario> *LF) {
    int option;
    do {
		// system("clear || cls");
		cout << "======================" << endl;
		cout << "   MENU FUNCIONARIO" << endl;
		cout << "======================" << endl << endl;
		cout << "1 - Ver Funcionarios" << endl;
		cout << "0 - Voltar" << endl;
		cout << endl << "Opcao: ";
		cin >> option;//1
		switch (option) {
		case 1:
			printFuncionario(LF);//1
			break;
		case 0:
			return;
        default:
            cout << "Opcao invalida!" << endl;
            break;
        }
        // system("pause");
    } while(option != 0);//1
}

/*
	Funcao: menuFuncionario
	@param LF: lista dinamica de funcionario
*/
void printFuncionario(List<funcionario>* LF) {
	node<funcionario>* pLF;
	cout << endl << "FUNCIONARIOS" << endl << endl;

	pLF = LF->HEAD;//1
	for (int i = 0; i < LF->size();i++) {//2 + 2N
		pLF->dado.imprime();//1
		pLF = pLF->prox;//1
	}
}