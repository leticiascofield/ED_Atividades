#include "ListaAdjacencia.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    try {
        if (argc < 2) {
            std::cerr << "Uso: " << argv[0] << " <opcao>" << std::endl;
            return 1;
        }

        ListaAdjacencia grafo;

        // Leitura dos dados do grafo
        int numVertices;
        std::cin >> numVertices;

        for (int i = 0; i < numVertices; ++i) {
            grafo.InsereVertice();
            int numVizinhos;
            std::cin >> numVizinhos;

            for (int j = 0; j < numVizinhos; ++j) {
                int vizinho;
                std::cin >> vizinho;
                grafo.InsereAresta(i, vizinho);
            }
        }

        // Execução das operações com base na opção fornecida
        std::string opcao = argv[1];

        if (opcao == "-d") {
            std::cout << grafo.QuantidadeVertices() << std::endl;
            std::cout << grafo.QuantidadeArestas() << std::endl;
            std::cout << grafo.GrauMinimo() << std::endl;
            std::cout << grafo.GrauMaximo() << std::endl;
        } else if (opcao == "-n") {
            for (int i = 0; i < grafo.QuantidadeVertices(); ++i) {
                grafo.ImprimeVizinhos(i);
                std::cout << std::endl;
            }
        } else if (opcao == "-k") {
            int grauMinimo = grafo.GrauMinimo();
            int numVertices = grafo.QuantidadeVertices();

            if (grauMinimo == numVertices - 1) {
                std::cout << "1" << std::endl;  // Grafo completo
            } else {
                std::cout << "0" << std::endl;  // Grafo não completo
            }
        } else {
            std::cerr << "Opcao invalida!" << std::endl;
            return 1;
        }
    } catch(const char* e){
        std::cerr << "Erro: " << e << std::endl;
    }

    return 0;
}
