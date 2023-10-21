#include <stdio.h>
#include <iostream>
#include "vertice.cpp"
#include <vector>
#include <unistd.h>

int main(int argc, char *argv[]) {

    /*if(argc > 2){
        char operacao = atoi(argv[1]);
        if(operacao == 'n'){
            std::cout << operacao;
        }
    }
    std::cout << atoi(argv[0]);
    std::cout << atoi(argv[1]); */
    char operaca;
    int n;

    std::cin >> operaca;
    std::cin >> n;

    int grau[n];
    ListaEncadeada* listaEncadeada = new ListaEncadeada[n];
    Vertice* vertice = new Vertice[n];

    for(int i = 0; i < n; i++){
       std::cin >> grau[i]; 
       vertice[i].grau = grau[i];
       for(int j = 0; j < grau[i]; j++){
        int aux;
        std::cin >> aux; 
        listaEncadeada[i].Adicionar(aux);
       }
       vertice[i].listaEncadeada = listaEncadeada[i];
    }


    for(int i = 0; i < n; i++){
        std::cout  << "Vértice " << i << " está conectado a: ";
        vertice[i].listaEncadeada.Imprimir();
        std::cout << std::endl;
    }

    if(operaca == 'n'){

    }

    delete[] listaEncadeada;
    delete[] vertice;

}