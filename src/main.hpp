#include "Lista.hpp"
#include "Fila.hpp"

#include "livro.hpp"
#include "funcionario.hpp"
#include "categorias.hpp"
#include "estante.hpp"
#include "pessoa.hpp"
#include "json.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <utility>

int menu();

void readJsonCategoria(List<categorias> *L);
void readJsonFuncionario(List<funcionario>* LF);
void readJsonLivro(Livro* L);
void readJsonEstante(List<estante> *LE);
void readJsonUsuario();

void InicializarBiblioteca(List<pessoa> *IdPessoas);
void saidaDePessoas(List<pessoa>* IdPessoas);
void pessoasNaBiBlioteca(List<pessoa>* IdPessoas);
void printAutores();