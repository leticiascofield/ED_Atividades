#include "../include/heap.hpp"

Heap::Heap(int maxsize) {
    tamanho = 0;
    data = new int[maxsize];
}

Heap::~Heap() {
    delete[] data;
}

void Heap::Inserir(int x) {
    data[tamanho] = x;
    HeapifyPorCima(tamanho);
    tamanho++;
}

int Heap::Remover() {
    int raiz = data[0];
    data[0] = data[tamanho - 1];
    tamanho--;
    HeapifyPorBaixo(0);
    return raiz;
}

bool Heap::Vazio() {
    return tamanho == 0;
}

int Heap::GetAncestral(int posicao) {
    return (posicao - 1) / 2;
}

int Heap::GetSucessorEsq(int posicao) {
    return 2 * posicao + 1;
}

int Heap::GetSucessorDir(int posicao) {
    return 2 * posicao + 2;
}

void Heap::HeapifyPorBaixo(int posicao) {
    int esq = GetSucessorEsq(posicao);
    int dir = GetSucessorDir(posicao);
    int menor = posicao;

    if (esq < tamanho && data[esq] < data[posicao]) {
        menor = esq;
    }

    if (dir < tamanho && data[dir] < data[menor]) {
        menor = dir;
    }

    if (menor != posicao) {
        // Troca os valores diretamente no array data
        int temp = data[posicao];
        data[posicao] = data[menor];
        data[menor] = temp;

        HeapifyPorBaixo(menor);
    }
}

void Heap::HeapifyPorCima(int posicao) {
    int ancestral = GetAncestral(posicao);

    if (posicao > 0 && data[posicao] < data[ancestral]) {
        // Troca os valores diretamente no array data
        int temp = data[posicao];
        data[posicao] = data[ancestral];
        data[ancestral] = temp;

        HeapifyPorCima(ancestral);
    }
}


