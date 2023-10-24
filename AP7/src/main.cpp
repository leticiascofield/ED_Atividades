#include <iostream>
#include "../include/heap.hpp"

int main() {
    int n;
    std::cin >> n;

    Heap minHeap(n);

    for (int i = 0; i < n; ++i) {
        int element;
        std::cin >> element;
        minHeap.Inserir(element);
    }

    while (!minHeap.Vazio()) {
        int removed = minHeap.Remover();
        std::cout << removed;
        if (!minHeap.Vazio()) {
            std::cout << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
