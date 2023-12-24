#include "TipoItem.hpp"

TipoItem::TipoItem() : chave(0) {}

TipoItem::TipoItem(int novaChave) : chave(novaChave) {}

int TipoItem::GetChave() const {
    return chave;
}

void TipoItem::SetChave(int novaChave) {
    chave = novaChave;
}

void TipoItem::Imprime() const {
    std::cout << chave << " ";
}