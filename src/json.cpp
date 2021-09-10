#include "main.hpp"

#include "biblioteca/json.hpp"
using json = nlohmann::json;

/*
	Funcao readJsonFuncionario
	@param LF: lista dinamica de funcionario que sera utilizada para a leitura de valores estaticos no arquivo .json
*/
void readJsonFuncionario(List<funcionario>* LF) {
	json js;
	ifstream file("arquivo.json");
	file >> js;//1

	for (int i = 0; i < js["funcionario"].size(); i++) {//2 + 2n + 4n
		json aux = js["funcionario"][i];

		LF->push({ aux["id"], aux["nome"], aux["usuario"], aux["senha"] });
	}
}

/*
	Funcao readJsonCategoria
	@param L: lista dinamica de categoria que sera utilizada para a leitura de valores estaticos no arquivo .json
*/
void readJsonCategoria(List<categorias>* L) {

	json j;
	ifstream file("arquivo.json");
	file >> j;//1

	for (long unsigned int i = 0; i < j["categorias"].size(); i++) {//2 + 2n + 2n
		json aux = j["categorias"][i];
		L->push({ aux["id"], aux["nome"] });
	}
}

/*
	Funcao readJsonLivro
	@param L: lista dinamica de livro que sera utilizada para a leitura de valores estaticos no arquivo .json
*/
void readJsonLivro(Livro* L) {
	FLVazia(L);
	ItemLivro item;

	string str;
	char* nome;
	int i;

	json js;
	ifstream file("arquivo.json");
	file >> js;//1

	for (i = 0; i < js["livro"].size(); i++) {//2 + 2n + 5n
		json aux = js["livro"][i];

		item.id = aux["id"];
		item.id_categoria = aux["categoria"];
		item.str = aux["nome"];

		LInsert(L, item);
	}
}

/*
	Funcao readJsonEstante
	@param LE: lista dinamica de estamte que sera utilizada para a leitura de valores estaticos no arquivo .json
	@param L: lista dinamica de livro que sera utilizada para buscar o id que estiver presente no arquivo .json da estante
*/
void readJsonEstante(List<estante>* LE, Livro* L) {
	json js;
	ifstream file("arquivo.json");
	file >> js;//1

	int i, j;

	estante est;
	ItemLivro item, temp;

	for (i = 0; i < js["estante"].size(); i++) {//2 + 2n + 3n
		json aux = js["estante"][i];//1

		est.id = aux["id"];//1
		FLVazia(&est.l);//1
		for (j = 0; j < aux["livro"].size(); j++) {//(2 + 2n + 2n + 6n/2) * n
			json livros = aux["livro"][j];//1

			item.id = livros["id"];//1

			if (sizeLivro(&est.l) < 30) {//1

				temp = LBusca(L, item.id);//1

				if (temp.id != -1) {//1
					item.nome = temp.nome;//1
					item.controle = true;//1
					LInsert(&est.l, item);//1
				}
				else
					cout << "O livro com ID:[" << item.id << "] nao foi encontrado" << endl;
			}
			else {
				cout << "Estante lotada" << endl;
				// system("pause");
				break;
			}

		}
		LE->push(est);
	}
}