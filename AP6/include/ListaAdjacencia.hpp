#ifndef LISTAADJACENCIA_HPP
#define LISTAADJACENCIA_HPP

#include "ListaEncadeada.hpp"

class ListaAdjacencia {
public:
    ListaAdjacencia();
    ~ListaAdjacencia();

    void InsereVertice();
    void InsereAresta(int v, int w);

    int QuantidadeVertices();
    int QuantidadeArestas();

    int GrauMinimo();
    int GrauMaximo();

    void ImprimeVizinhos(int v);

private:
    ListaEncadeada* array;
    int numVertices;
};

#endif
