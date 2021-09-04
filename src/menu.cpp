#include "menu.hpp"

// struct stackNode {
//     int data;
//     struct stackNode *nextPtr;
// };

// typedef struct stackNode stackNode;
// typedef stackNode *StackNodePtr;

void menuBiblioteca(Livro* L, List<funcionario>* LF, List<categorias>* LC, List<estante>* LE, List<pessoa>* LP) {
	int option;
	do {
		//system("clear || cls");
		cout << "======================" << endl;
		cout << "    MENU BIBLIOTECA" << endl;
		cout << "======================" << endl << endl;
		cout << "1  - Cadastrar Livro" << endl;
		cout << "2  - Editar    Livro" << endl;
		cout << "3  - Remover   Livro" << endl;
		cout << "4  - Pesquisar Livro" << endl;
		cout << "5  - Pesquisar Categoria" << endl;
		cout << "6  - Exibir Funcionarios" << endl;
		cout << "7  - Acessar Estante" << endl;
		cout << "8  - Imprimir Tudo" << endl << endl;

		cout << "9  - Simular entrada de pessoa" << endl;
		cout << "10 - Simular saida de pessoa" << endl << endl;

		// implementar adição a fila; adição a biblioteca e remoção da biblioteca
		cout << "0 - Voltar" << endl;
		cout << endl << "Opcao: ";
		cin >> option;
		switch (option) {
		case 1:
			cadastrarLivro(L, LC);
			break;
		case 2:
			editarLivro(L, LC);
			break;
		case 3:
			// remover livro
			// removerLivro(L, LC);
			break;
		case 4:
			// pesquisar livro
			break;
		case 5:
			// pesquisar categoria
			break;
		case 6:
			// exibir funcionarios
			break;
		case 7:
			// acessar estante
			break;
		case 8:
			printAll(L, LF, LC, LE, LP);
			system("pause");
			break;
		case 9:
			pessoasNaBiBlioteca(LP);
			break;
		case 10:
			saidaDePessoas(LP);
			break;
		case 0:
			return;
		default:
			cout << "Opcao invalida!" << endl << endl;
			system("pause");
			break;
		}
	} while (option != 0);
}

void cadastrarLivro(Livro* L, List<categorias>* LC) {
	string nome;
	// int quantidade;
	int categoria;
	bool aux = false;

	ItemLivro item;
	node<categorias>* pLC;

	// system("cls || clear");
	cout << "=====================" << endl;
	cout << "    CADASTRO LIVRO" << endl;
	cout << "=====================" << endl << endl;

	cout << "Informe o nome do livro: ";
	fflush(stdin);
	cin >> nome;

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

void editarLivro(Livro* L, List<categorias>* LC) {
	int idLivro;
	int option;
	char excluir;
	bool found = false;
	int counter = 0;
	BlockLivro *temp;

	// dados que serao trazidos do livro procurado
	int id;
	int id_categoria;
	char *nome;
	// ======================

	ItemLivro item;
	node<categorias>* pLC;

	system("cls || clear");
	cout << "=====================" << endl;
	cout << "    EDITAR LIVRO" << endl;
	cout << "=====================" << endl;
	
	printLivro(L);

	cout << endl << endl << "Escolha o ID do que livro deseja editar: ";
	cin >> idLivro;
	system("cls || clear");

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
				cin >> nome;
				temp->data.nome = nome;
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
				LRemove(L, temp->data);
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

bool realizarLogin(funcionario* func, List<funcionario>* LF) {
	string usuario, senha;
	node<funcionario>* pLF;

	// system("cls || clear");
	cout << "=====================" << endl;
	cout << "        LOGIN" << endl;
	cout << "=====================" << endl << endl;

	cout << "Usuario: ";
	cin >> usuario;
	cout << "Senha: ";
	cin >> senha;

	pLF = LF->HEAD;
	for (int i = 0; i < LF->size();i++) {
		if (pLF->dado.usuario.compare(usuario) == 0) {
			if (pLF->dado.senha.compare(senha) == 0) {
				func->id = pLF->dado.id;
				func->nome = pLF->dado.nome;

				return true;
			}
		}
		pLF = pLF->prox;
	}
	return false;
}

void printAll(Livro* L, List<funcionario>* LF, List<categorias>* LC, List<estante>* LE, List<pessoa>* LP) {
	printLivro(L);
	printFuncionario(LF);
	printCategoria(LC);
	printEstante(LE);
	printPessoa(LP);

	adicionarLivroPessoa(LE, LP);
}

void InicializarBiblioteca(List<pessoa>* IdPessoas) {
	for (int i = 0; i < 10; i++) {
		IdPessoas->push(i + 1);
	}
}

void printPessoa(List<pessoa>* IdPessoas) {
	cout << "PESSOAS" << endl << endl;

	if (IdPessoas->size() == 0) {
		cout << "Nao possui leitores na biblioteca" << endl << endl;
		return;
	}

	node<pessoa>* pId;
	pId = IdPessoas->HEAD;

	for (int i = 0; i < IdPessoas->size(); i++) {
		pId->dado.imprime();
		pId = pId->prox;
	}
	cout << endl << endl;
}

void printFuncionario(List<funcionario>* LF) {
	node<funcionario>* pLF;
	cout << endl << "FUNCIONARIOS" << endl << endl;

	pLF = LF->HEAD;
	for (int i = 0; i < LF->size();i++) {
		pLF->dado.imprime();
		pLF = pLF->prox;
	}
}

void printCategoria(List<categorias>* LC) {
	cout << endl << "CATEGORIAS" << endl << endl;

	node<categorias>* pLC;
	pLC = LC->HEAD;
	for (int i = 0; i < LC->size();i++) {
		pLC->dado.imprime();
		pLC = pLC->prox;
	}
}

void printEstante(List<estante>* LE) {
	cout << endl << "ESTANTES" << endl << endl;

	node<estante>* pLE;
	pLE = LE->HEAD;

	for (int i = 0; i < LE->size();i++) {
		pLE->dado.imprime(sizeLivro(&pLE->dado.l));
		cout << endl << "===============================" << endl << endl;
		pLE = pLE->prox;
	}
}

void pessoasNaBiBlioteca(List<pessoa>* IdPessoas) {
	if (IdPessoas->size() < 10) {
		IdPessoas->push((IdPessoas->size() != 0) ? (IdPessoas->TAIL->dado.id + 1) : 1);
		cout << "Uma pessoa entrou na biblioteca!!" << endl << endl;
	}
	else {
		cout << endl << "BIBLIOTECA LOTADA!!" << endl;
		cout << "Espere no lado de fora!" << endl << endl;
	}
}

void saidaDePessoas(List<pessoa>* IdPessoas) {
	if (IdPessoas->size() == 0)
		cout << "Nao possui leitores na biblioteca" << endl << endl;
	else {
		IdPessoas->pop();
		cout << "Uma pessoa saiu da biblioteca!!" << endl << endl;
	}
}

void adicionarLivroPessoa(List<estante>* LE, List<pessoa>* LP) {
	cout << "head: " << LP->HEAD->dado.id << endl;
}

// REMOVE O LIVRO DA ESTANTE E O INCLUI NA PILHA

// void removerLivro(Livro* L, List<categorias>* LC){
// 	//String nomeLivro;

// 	StackNodePtr stackPtr = NULL;

//     printf("Digite o nome do Livro: ", *sizeLivro);
//     cin >> sizeLivro;
//     push(&stackPtr, sizeLivro);
//     printStack(stackPtr);
// }

// void push(StackNodePtr *topPtr, int info){
//     StackNodePtr newPtr;//ponteiro para novo nó

//     //insere o nó no topo da pilha
//     if(newPtr != NULL){
//         newPtr->data = info;
//         newPtr->nextPtr = *topPtr;
//         *topPtr = newPtr;
//     }
//     else { // se não tiver espaço disponível
//         printf("%d não inserido. Nenhuma memória disponível.\n", info);
//     }
// }

// void printStack(StackNodePtr currentPtr){

//     //se a pilha estiver vazia
//     if(currentPtr == NULL){
//         printf("A pilha está vazia.\n\n");
//     }
//     else{
//         printf("A pilha é: \n");

//         //enquanto não chega ao final da pilha
//         while(currentPtr != NULL){
//             printf("%d ---> ", currentPtr->data);
//             currentPtr=currentPtr->nextPtr;
//         }

//         printf("NULL\n\n");
//     }
// }

// int isEmpty(StackNodePtr topPtr)
// {
//     return topPtr == NULL;
// }