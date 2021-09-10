#ifndef MENUS_HPP
#define MENUS_HPP

#include "main.hpp"

// ==============================
//              MAIN
// ==============================

bool realizarLogin(funcionario* func, List<funcionario>* LF);

// ==============================
//           BIBLIOTECA
// ==============================

void menuBiblioteca(Livro* L, List<funcionario>* LF, List<categorias>* LC, List<estante>* LE, Fila<pessoa>* FP);
void printAll(Livro* L, List<funcionario>* LF, List<categorias>* LC, List<estante>* LE, Fila<pessoa>* FP);

// ==============================
//             LIVRO
// ==============================

void menuLivro(Livro* L, List<categorias> *LC, List<estante> *LE);
void cadastrarLivro(Livro *L, List<categorias>* LC);
void editarLivro(Livro* L, List<categorias>* LC, List<estante> *LE);
void removerLivro(Livro* L);
void printCategoria(List<categorias>* LC);

// ==============================
//            ESTANTE
// ==============================

void menuEstante(List<estante> *LE, Fila<pessoa> *FP, Livro *L);
int pesquisarLivroEstante(List<estante>* LE);
void inserirNaEstante(Livro *L, List<estante> *LE);
void printEstante(List<estante>* LE, bool aux);
void pegarLivro(List<estante>* LE, Fila<pessoa>* FP, Livro *L);
void retornarEstante(List<estante>* LE, PilhaLivro* p);

// ==============================
//          FUNCIONARIO
// ==============================

void menuFuncionario(List<funcionario>* LF);
void printFuncionario(List<funcionario>* LF);

// ==============================
//            PESSOA
// ==============================

void printPessoa(Fila<pessoa> *FP);
void saidaDePessoas(Fila<pessoa>* FP, List<estante>* LE);
void entradaDePessoas(Fila<pessoa> *FP);

#endif