#include "Lista.hpp"
#include "livro.hpp"
#include "funcionario.hpp"
#include "categorias.hpp"
#include "estante.hpp"
#include "json.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <utility>

int menu();

// void readJsonCategoria();//receber parametro adequado
void readJsonCategoria(List<categorias> *L);//receber parametro adequado
void readJsonFuncionario(List<funcionario>* LF);
void readJsonLivro(Livro* L);
void readJsonEstante(List<estante> *LE);
void readJsonUsuario();//receber parametro adequado

void printAll(Livro* L, List<funcionario>* LF, List<categorias> *LC, List<estante> *LE);