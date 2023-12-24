#include "ListaAdjacencia.hpp"
#include "ListaEncadeada.hpp"
#include "TipoItem.hpp"

ListaAdjacencia::ListaAdjacencia() : array(nullptr), numVertices(0) {}

ListaAdjacencia::~ListaAdjacencia() {
    delete[] array;
}

void ListaAdjacencia::InsereVertice() {
    ListaEncadeada* novaLista = new ListaEncadeada[numVertices + 1];

    for (int i = 0; i < numVertices; ++i) {
        novaLista[i] = array[i];
    }

    delete[] array;
    array = novaLista;
    ++numVertices;
}

void ListaAdjacencia::InsereAresta(int v, int w) {
    if (v < 0 || v >= numVertices || w < 0 || w >= numVertices) {
        throw "Vertice invalido!";
    }

    array[v].InsereInicio(TipoItem(w));
    array[w].InsereInicio(TipoItem(v));
}

int ListaAdjacencia::QuantidadeVertices() {
    return numVertices;
}

int ListaAdjacencia::QuantidadeArestas() {
    int count = 0;

    for (int i = 0; i < numVertices; ++i) {
        count += array[i].Quantidade();
    }

    // Cada aresta foi contada duas vezes (uma vez para cada vértice), então dividimos por 2
    return count / 2;
}

int ListaAdjacencia::GrauMinimo() {
    if (numVertices == 0) {
        return 0;
    }

    int grauMinimo = array[0].Quantidade();

    for (int i = 1; i < numVertices; ++i) {
        int grauAtual = array[i].Quantidade();
        if (grauAtual < grauMinimo) {
            grauMinimo = grauAtual;
        }
    }

    return grauMinimo;
}

int ListaAdjacencia::GrauMaximo() {
    if (numVertices == 0) {
        return 0;
    }

    int grauMaximo = array[0].Quantidade();

    for (int i = 1; i < numVertices; ++i) {
        int grauAtual = array[i].Quantidade();
        if (grauAtual > grauMaximo) {
            grauMaximo = grauAtual;
        }
    }

    return grauMaximo;
}

void ListaAdjacencia::ImprimeVizinhos(int v) {
    if (v < 0 || v >= numVertices) {
        throw "ERRO: Vertice invalido!";
    }

    array[v].Imprime();
}
