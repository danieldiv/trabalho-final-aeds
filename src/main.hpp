#include "Lista.hpp"
#include "livro.hpp"
#include "funcionario.hpp"

#include <string>
#include <fstream>
#include <iostream>
// #include <stdbool.h>

int menu();
void login(funcionario* func, List<funcionario>* LF);
bool realizarLogin(funcionario* func, string usuario, string senha, List<funcionario> *LF);
void integrantes();

void readJsonCategoria();//receber parametro adequado
void readJsonFuncionario(List<funcionario>* LF);
void readJsonLivro(Livro* L);
void readJsonUsuario();//receber parametro adequado

void printAll(Livro* L, List<funcionario>* LF);