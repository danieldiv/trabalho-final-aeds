#include "main.hpp"

#include "json.hpp"
using json = nlohmann::json;

void readJsonFuncionario(List<funcionario>* LF) {
	json js;
	ifstream file("arquivo.json");
	file >> js;

	for (int i = 0; i < js["funcionario"].size(); i++) {
		json aux = js["funcionario"][i];

		LF->push({ aux["id"], aux["nome"], aux["usuario"], aux["senha"] });
	}
}

void readJsonCategoria(List<categorias> *L) {

	// List<categorias> L;
	// node<categorias> *pL = L->HEAD;
	json j;
  	ifstream file("arquivo.json");
  	// ifstream file("j.json");
  	file >> j;

	for(long unsigned int i = 0; i <j["categorias"].size(); i++){
		json aux = j["categorias"][i];
		// json aux = j["categoias"][i];
		L->push({aux["id"], aux["nome"]});
	}
}

void readJsonLivro(Livro* L) {
	FLVazia(L);
	ItemLivro item;

	string str;
	char* nome;
	int i;

	json js;
	ifstream file("arquivo.json");
	file >> js;

	for (i = 0; i < js["livro"].size(); i++) {
		json aux = js["livro"][i];

		item.id = aux["id"];
		item.id_categoria = aux["categoria"];
		item.str = aux["nome"];
		item.quantidade = aux["quantidade"];

		LInsert(L, item);
		quanLivro++;
	}
}