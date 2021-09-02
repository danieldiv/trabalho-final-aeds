#ifndef MENUS_HPP
#define MENUS_HPP

#include "main.hpp"

void menuBiblioteca(Livro* L, List<funcionario>* LF, List<categorias>* LC, List<estante>* LE, List<pessoa>* LP);

bool realizarLogin(funcionario* func, List<funcionario>* LF);

void printAll(Livro* L, List<funcionario>* LF, List<categorias>* LC, List<estante>* LE, List<pessoa>* LP);
void printFuncionario(List<funcionario>* LF);
void printCategoria(List<categorias>* LC);
void printEstante(List<estante>* LE);
void printPessoa(List<pessoa> *IdPessoas);

void cadastrarLivro(Livro *L, List<categorias>* LC);

#endif