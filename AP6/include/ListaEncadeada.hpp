#ifndef LISTAENCADEADA_HPP
#define LISTAENCADEADA_HPP

#include "TipoCelula.hpp"

class ListaEncadeada {
public:
    ListaEncadeada();
    ~ListaEncadeada();

    TipoItem GetItem(int pos);
    void SetItem(TipoItem item, int pos);
    void InsereInicio(TipoItem item);
    void InsereFinal(TipoItem item);
    void InserePosicao(TipoItem item, int pos);
    TipoItem RemoveInicio();
    TipoItem RemoveFinal();
    TipoItem RemovePosicao(int pos);
    TipoItem Pesquisa(int c);
    void Imprime();
    void Limpa();
    int Quantidade() const;

private:
    TipoCelula* primeiro;
    TipoCelula* ultimo;
    int tamanho;
    TipoCelula* Posiciona(int pos, bool antes);
};

#endif
