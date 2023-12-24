#include "ListaEncadeada.hpp"

ListaEncadeada::ListaEncadeada() : primeiro(new TipoCelula()), ultimo(primeiro), tamanho(0) {}

ListaEncadeada::~ListaEncadeada() {
    Limpa();
    delete primeiro;
}

TipoCelula* ListaEncadeada::Posiciona(int pos, bool antes) {
    TipoCelula* p = primeiro;
    int i;

    if ((pos > tamanho) || (pos <= 0))
        throw "ERRO: Posicao Invalida!";

    for (i = 1; i < pos; i++) {
        p = p->prox;
    }

    if (!antes)
        p = p->prox;

    return p;
}

TipoItem ListaEncadeada::GetItem(int pos) {
    TipoCelula* p = Posiciona(pos, true);
    return p->item;
}

void ListaEncadeada::SetItem(TipoItem item, int pos) {
    TipoCelula* p = Posiciona(pos, true);
    p->item = item;
}

void ListaEncadeada::InsereInicio(TipoItem item) {
    TipoCelula* nova = new TipoCelula();
    nova->item = item;
    nova->prox = primeiro->prox;
    primeiro->prox = nova;
    tamanho++;

    if (ultimo == primeiro)
        ultimo = nova;
}

TipoItem ListaEncadeada::RemoveInicio() {
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";

    TipoCelula* p = primeiro->prox;
    primeiro->prox = p->prox;
    tamanho--;

    if (primeiro->prox == nullptr)
        ultimo = primeiro;

    TipoItem aux = p->item;
    delete p;

    return aux;
}

void ListaEncadeada::Imprime() {
    TipoCelula* p = primeiro->prox;

    while (p != nullptr) {
        // Supondo que TipoItem tenha um método Imprime
        p->item.Imprime();
        p = p->prox;
    }

    printf("\n");
}

void ListaEncadeada::Limpa() {
    TipoCelula* p = primeiro->prox;

    while (p != nullptr) {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }

    ultimo = primeiro;
    tamanho = 0;
}

int ListaEncadeada::Quantidade() const {
    return tamanho;
}
