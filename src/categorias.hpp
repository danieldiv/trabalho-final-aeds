#ifndef CATEGORIAS_HPP
#define CATEGORIAS_HPP

#include <string>
#include <iostream>
#include "Lista.hpp"

using namespace std;

struct categorias{
    int id;
    string nome;

    void imprime();

    categorias() = default;
    categorias(int id, string nome) : id(id), nome(nome) {}
};
#endif