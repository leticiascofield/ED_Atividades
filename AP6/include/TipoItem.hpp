#ifndef TIPOITEM_HPP
#define TIPOITEM_HPP

#include <iostream>

class TipoItem {
public:
    TipoItem();
    TipoItem(int novaChave = 0);
    int GetChave() const;
    void SetChave(int chave);
    void Imprime() const;

private:
    int chave;
};

#endif
