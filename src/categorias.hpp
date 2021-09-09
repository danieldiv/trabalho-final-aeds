/*
    este .hpp sera responsavel pela estrutura da categoria a ser salva
*/

#ifndef CATEGORIAS_HPP
#define CATEGORIAS_HPP

#include <string>
#include <iostream>

using namespace std;

struct categorias{
    int id;
    string nome;

    void imprime();
    bool buscarCat(int idCat);

    int getId();

    categorias() = default;
    categorias(int id, string nome) : id(id), nome(nome) {}
};
#endif