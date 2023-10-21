#include <iostream>
#include "node.cpp"

struct ListaEncadeada {

    Node* inicial;

    ListaEncadeada(): inicial(nullptr) {}

    void Adicionar(int data) {
        Node* newNode = new Node(data);
        newNode->next = nullptr;

        if (inicial == nullptr) {
            // Se a lista estiver vazia, o novo nó será o primeiro nó
            inicial = newNode;
        } else {
            // Caso contrário, percorre a lista para encontrar o último nó
            Node* temp = inicial;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            // Adiciona o novo nó no final
            temp->next = newNode;
        }
    }

    void Imprimir() {
        Node* temp = inicial;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    ~ListaEncadeada() {
        Node* temp = inicial;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

};
