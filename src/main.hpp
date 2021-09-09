#include "estrutura/Lista.hpp"
#include "estrutura/Fila.hpp"
#include "biblioteca/json.hpp"

#include "livro.hpp"
#include "funcionario.hpp"
#include "categorias.hpp"
#include "estante.hpp"
#include "pessoa.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <utility>

int menu();

void readJsonCategoria(List<categorias> *L);
void readJsonFuncionario(List<funcionario>* LF);
void readJsonLivro(Livro* L);
void readJsonEstante(List<estante>* LE, Livro *L);
void readJsonUsuario();

void InicializarBiblioteca(List<pessoa> *LP);
void printAutores();