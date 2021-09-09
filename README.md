<h1 align="center">TRABALHO FINAL DE AED</h1>

### Proposta

- Sistema de acesso aos livros de uma biblioteca, que permite que um usuário entre na biblioteca e retire um livro atravez do login de um funcionário.

### Participantes

- Daniel Alves Sanches

- Julia Mello Lopes Gonçalves

- Leonardo de Oliveira Campos

- Lucas de Souza Gontijo

### Sumário
<!--ts-->
   * [Copilação](#Copilação)
   * [Informações](#Informações)
   * [Menu](#Menu)
   * [Login](#Login)
   * [Funcionamento](#Funcionamento)
   * [CustoComputacional](#CustoComputacional)
<!--te-->

### Copilação 

Comandos para que o programa copile em seu terminal:

      make
      make run

### Informações

- A biblioteca iniciara cheia, então para entrar na biblioteca é necessário que você retire uma pessoa primeiro.
- Livro não terá quantidade, apenas a estante.
- Como não pode utilizar uma lista para os leitores dentro da biblioteca, foi utilizado a fila, logo, apenas o primeiro da fila pode pegar no maximo 5 livros, o proximo so pode pegar os livros apoz o primeiro sair.

### Menu

Ao iniciar o programa sera possivel visualizar o seguinte menu:

![image](https://user-images.githubusercontent.com/84408875/132755696-4a92e6d5-b552-415f-a6d9-fe7f4bf6e994.png)

Nela sera possiveel fazer loguin, ver as informações dos colaboradores do projeto e sair do programa. Caso escolha o opção numero 1, sera necessário inserir as informações de um funcionário de seu nome de usuário e senha(ifrmações encontradas na parte de [Login](#Login)), como mostra a imagem a abaixo:

![image](https://user-images.githubusercontent.com/84408875/132755822-2a23aceb-b4cf-4f8a-8200-0a81b1dc2535.png)

Em seguida você podera ter acesso ao programa que disponibiliza as funçoes mostraadas a baixo:

![image](https://user-images.githubusercontent.com/84408875/132756724-ba20ad77-3bf2-4c31-9cfa-02314d0ea2f8.png)

Escolha uma das opções e de inicio a sua navegação.

### Login

- Para realizar o login, utilize um dos usuarios abaixo:
  - usuario: usuA | senha: senha123

  - usuario: usuB | senha: senha456

  - usuario: usuC | senha: senha789

  - usuario: usuD | senha: senhaLG

### Funcionamento 

A partir do menu sera possivel ter acesso a varios comandos, agora eu irei explicar o que com cada comando sera possivel fazer.

##### Cadastrar livro no sistema

 Atraves na função a baixo sera possivel cadastrar livros ao sistema:
 
   	void cadastrarLivro(Livro* L, List<categorias>* LC) {
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

Atrasvez de uma estrutura de lista sera posssivel organizar as entradas dos livros adcionados.
  
##### Editar um livro no sistema
  
  Nessa opção sera possivel editar os livros do sistema editando as lsitas de categorias e a estante, como é possivel ver a baixo:
  
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

##### AdcionarLivroPessoa

Nessa opção sera possivel que uma pessoa remova um livro para ler atravez de uma organização da lista, como é mostrado abaixo: 

	void adicionarLivroPessoa(List<estante>* LE, List<pessoa>* LP) {

	int id;

	printEstante(LE, true);
	system("pause");

	cout << "Escolha: " << endl;
	cin >> id;

	LE->push(id);
	printEstante(LE, false);
	system("pause");

	cout << "Tenha uma boa leitura!" << endl;
	system("pause");
	}

##### Pesquisar livro na estante

Na quarta opção sera posssivel pesquisar um livro na estante atravez da função abaixo:

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

##### Pesquisar categoria

	

##### Inserir na estante

Nessa aopção sera possivel inserir um livro a estante como é posssivel ver a baixo:

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

##### Acessar Estante



### CustoComputacional

Custo Computacional do nosso projeto:

## Tasks

> Login do sistema :heavy_check_mark: 🔴

> Menu de navegação (principal => submenus devem ser feitos com as funções) :heavy_check_mark: 🟡 (Lucas)

> Valor inicial dentro do arquivo.json  para as categorias :heavy_check_mark: 🔴

> Valor inicial dentro do arquivo.json  para as permissões :x:

> Valor inicial dentro do arquivo.json  para a(s) estante(s) :heavy_check_mark: 🟢

> Valor inicial dentro do arquivo.json  para os livros com a categoria :heavy_check_mark: 🔴

> Valor inicial dentro do arquivo.json  para os funcionarios :heavy_check_mark: 🔴

> Criar uma lista para armazenar os livros :heavy_check_mark: 🟡

> Criar uma lista para armazenar os categorias :heavy_check_mark: 🔴

> Criar uma pilha para livros retirados da lista (estante) :warning: 🟡 (Leonardo)

> Controle da quantidade de pessoas dentro da biblioteca :heavy_check_mark: 🟢

> Controle da quantidade de livros :heavy_check_mark: 🟡

> Controle de livros retirados e livros devolvidos (LR e LD) :warning: 🟢

> Caso tenha tempo: ordernação dos livros em ordem alfabetica :warning: 🟢

> CRUD da categoria :warning:

> CRUD do livro :warning: (Lucas)

> CRUD da estante :warning:

> CRUD dos funcionários :warning:

### Informações

- CRUD
  - Create (Cadastrar), Read (Buscar), Update (Atualizar), Delete (Deletar)

- 🔴 Prioridade alta
- 🟡 Prioridade media
- 🟢 Prioridade baixa

