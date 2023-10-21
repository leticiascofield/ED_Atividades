#include "../include/graph.hpp"
#include <stdio.h>



/*  Você pode inserir os includes necessários para que sua classe funcione.
 * Nenhuma outra alteração neste arquivo é permitida
 */
        Grafo::Grafo() {
            vertices = ListaAdjacencia();
        }
        Grafo::~Grafo() {}

        void Grafo::InsereVertice(){
            No* temp = vertices.verticeInicial_;
            int count = 0;

            // Conta o número de vértices existentes
            while (temp != nullptr) {
                temp = temp->proximo_;
                count++;
                std::cout << "teste" << std::endl;
            }
            std::cout << "teste2" << std::endl;
            // Adiciona um novo vértice ao grafo
            vertices.AdicionarVertice(count);
            std::cout << "teste3" << std::endl;
        }
            

        void Grafo::InsereAresta(int v, int w) {}

        int Grafo::QuantidadeVertices(){
            No* temp = vertices.verticeInicial_;
            int count = 0;
            while (temp != nullptr) {
            No* proximoNo = temp->proximo_;
            count++;
            }
            return count;
        }

        int Grafo::QuantidadeArestas() {
            return 0;
        }

        int Grafo::GrauMinimo() {
            return 0;
        }
        int Grafo::GrauMaximo() {
            return 0;
        }

        void Grafo::ImprimeVizinhos(int v) {}

        ListaAdjacencia vertices;
        

