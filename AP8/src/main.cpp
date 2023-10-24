#include <iostream>
#include <vector>
#include "../include/unionFind.hpp"


void bubbleSort(std::vector<Aresta>& arestas) {
    int n = arestas.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arestas[j].custo > arestas[j + 1].custo) {
                Aresta temp = arestas[j];
                arestas[j] = arestas[j + 1];
                arestas[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<Aresta> arestas;
    for (int i = 0; i < m; ++i) {
        Aresta aresta;
        std::cin >> aresta.u >> aresta.v >> aresta.custo;
        arestas.push_back(aresta);
    }

    bubbleSort(arestas);

    UnionFind unionFind(n);

    int custoTotal = 0;
    for (const auto& aresta : arestas) {
        if (unionFind.Find(aresta.u) != unionFind.Find(aresta.v)) {
            unionFind.Union(aresta.u, aresta.v);
            custoTotal += aresta.custo;
        }
    }

    std::cout << custoTotal << std::endl;

    return 0;
}
