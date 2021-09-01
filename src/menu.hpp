#ifndef MENUS_HPP
#define MENUS_HPP

#include "main.hpp"

void menuBiblioteca(Livro* L, List<funcionario>* LF, List<categorias>* LC, List<estante>* LE);
void printAutores();
bool realizarLogin(funcionario* func, List<funcionario>* LF);
void printAll(Livro* L, List<funcionario>* LF, List<categorias>* LC, List<estante>* LE);

void cadastrarLivro(Livro *L, List<categorias>* LC);

#endif