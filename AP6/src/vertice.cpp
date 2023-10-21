#include <iostream>
#include "listaEncadeada.cpp"

struct Vertice {
    int grau;
    ListaEncadeada listaEncadeada;

    Vertice(): grau(0), listaEncadeada() {}

    Vertice(int n, const ListaEncadeada& listaA) : grau(n), listaEncadeada(listaA) {
        // Nada mais precisa ser feito no construtor
    }
};