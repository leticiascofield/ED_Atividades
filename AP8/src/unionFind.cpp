#include "../include/unionFind.hpp"

UnionFind::UnionFind(int quantidade_subconjuntos) {
    tamanho = quantidade_subconjuntos;
    subconjuntos = new Subconjunto[quantidade_subconjuntos];
    for (int i = 0; i < quantidade_subconjuntos; ++i) {
        Make(i);
    }
}

UnionFind::~UnionFind() {
    delete[] subconjuntos;
}

void UnionFind::Make(int x) {
    subconjuntos[x].representante = x;
    subconjuntos[x].rank = 0;
}

int UnionFind::Find(int x) {
    if (x != subconjuntos[x].representante) {
        subconjuntos[x].representante = Find(subconjuntos[x].representante);
    }
    return subconjuntos[x].representante;
}

void UnionFind::Union(int x, int y) {
    int representante_x = Find(x);
    int representante_y = Find(y);

    if (subconjuntos[representante_x].rank < subconjuntos[representante_y].rank) {
        subconjuntos[representante_x].representante = representante_y;
    } else if (subconjuntos[representante_x].rank > subconjuntos[representante_y].rank) {
        subconjuntos[representante_y].representante = representante_x;
    } else {
        subconjuntos[representante_y].representante = representante_x;
        subconjuntos[representante_x].rank++;
    }
}
