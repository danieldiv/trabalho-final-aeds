#include "Lista.hpp"
#include "livro.hpp"
#include "funcionario.hpp"

#include <string>
#include <fstream>
#include <iostream>

int menu();
void integrantes();

void readJsonCategoria();//receber parametro adequado
void readJsonFuncionario(List<funcionario>* LF);
void readJsonLivro(Livro* L);
void readJsonUsuario();//receber parametro adequado

void printAll(Livro* L, List<funcionario>* LF);