#ifndef MENUS_HPP
#define MENUS_HPP

#include "main.hpp"
#include <string>
#include <stdlib.h>
#include <stdio.h>

struct stackNode;

typedef struct stackNode stackNode;
typedef stackNode *StackNodePtr;

void menuBiblioteca(Livro* L, List<funcionario>* LF, List<categorias>* LC, List<estante>* LE, List<pessoa>* LP);

bool realizarLogin(funcionario* func, List<funcionario>* LF);

void printAll(Livro* L, List<funcionario>* LF, List<categorias>* LC, List<estante>* LE, List<pessoa>* LP);
void printFuncionario(List<funcionario>* LF);
void printCategoria(List<categorias>* LC);
void printEstante(List<estante>* LE);
void printPessoa(List<pessoa> *IdPessoas);

void cadastrarLivro(Livro *L, List<categorias>* LC);
void editarLivro(Livro* L, List<categorias>* LC);
void removerLivro(Livro* L, List<categorias>* LC);

void adicionarLivroPessoa(List<estante>* LE, List<pessoa>* IdPessoas);

int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void push(StackNodePtr *topPtr, int info);

void adicionarLivroPessoa(List<estante>* LE, List<pessoa>* LP);

#endif