#include <stdio.h>
#include "../include/graph.hpp"

using std::cin;
using std::cout;

int main() {

    int n; // quantidade de vertices
    cin >> n;
    int grau;

    ListaAdjacencia* lista[n];
    for(int i=0; i < n; i++){
        lista[i] = new ListaAdjacencia; // fazer um for pra instanciar
        lista[i]->vizinhos_ = new ListaAdjacencia;
    }

    int aux;

    for(int i = 0; i < n; i++){
        cin >> grau;
        lista[i]->AdicionarVertice(i);
        for(int j = 0; j < grau; j++){
            cin >> aux;
            lista[i]->vizinhos_->AdicionarVertice(aux);
        }
    }

    Grafo* grafo = new Grafo();
    
        grafo->InsereVertice();
         cout << "testeeeee";
        grafo->InsereVertice();
    cout << "testeeeee";
    

    int x = grafo->QuantidadeVertices();
    cout << x;
    for(int i = 0; i < n; i++){
        std::cout  << "Vértice " << i << " está conectado a: ";
        lista[i]->vizinhos_->Imprimir();
    }

}