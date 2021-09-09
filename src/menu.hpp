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

void menuBiblioteca(Livro* L, List<funcionario>* LF, List<categorias>* LC, List<estante>* LE, List<pessoa>* LP);
void printAll(Livro* L, List<funcionario>* LF, List<categorias>* LC, List<estante>* LE, List<pessoa>* LP);

// ==============================
//             LIVRO
// ==============================

void menuLivro(Livro* L, List<categorias> *LC, List<estante> *LE);
void cadastrarLivro(Livro *L, List<categorias>* LC);
void editarLivro(Livro* L, List<categorias>* LC, List<estante> *LE);
void removerLivro(Livro* L, int id);
void printCategoria(List<categorias>* LC);

// ==============================
//            ESTANTE
// ==============================

void menuEstante(List<estante> *LE);
void pesquisarLivroEstante(List<estante>* LE);
void inserirNaEstante(Livro *L, List<estante> *LE);
void printEstante(List<estante>* LE, bool aux);

// ==============================
//          FUNCIONARIO
// ==============================

void menuFuncionario(List<funcionario>* LF);
void printFuncionario(List<funcionario>* LF);

// ==============================
//            PESSOA
// ==============================

void printPessoa(List<pessoa> *LP);
void saidaDePessoas(List<pessoa>* IdPessoas);
void entradaDePessoas(List<pessoa>* IdPessoas);

// void adicionarLivroPessoa(List<estante>* LE, List<pessoa>* IdPessoas);
// void adicionarLivroPessoa(List<estante>* LE, List<pessoa>* LP);

#endif