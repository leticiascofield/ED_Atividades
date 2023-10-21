#include "no.cpp"
#include <iostream>

class ListaAdjacencia {
    public:
    No* verticeInicial_;
    ListaAdjacencia* vizinhos_;

    ListaAdjacencia() : verticeInicial_(nullptr) {}

    ListaAdjacencia(No* vertice, ListaAdjacencia* vizinhos){
        verticeInicial_ = vertice;
        vizinhos_ = vizinhos;
    }

    void AdicionarVertice(int vertice) {
        No* newNo = new No();
        newNo->valor_ = vertice;
        newNo->proximo_ = nullptr;

        if (verticeInicial_ == nullptr) {
            verticeInicial_ = newNo;
        } else {
            No* temp = verticeInicial_;
            while (temp->proximo_ != nullptr) {
                temp = temp->proximo_;
            }
            temp->proximo_ = newNo;
        }
    }

    void Imprimir() {
        No* temp = verticeInicial_;
        while (temp != nullptr) {
            std::cout << temp->valor_ << " ";
            temp = temp->proximo_;
        }
        std::cout << std::endl;
    }

    ~ListaAdjacencia() {
        No* temp = verticeInicial_;
        while (temp != nullptr) {
            No* proximoNo = temp->proximo_;
            delete temp;
            temp = proximoNo;
        }
    }

};