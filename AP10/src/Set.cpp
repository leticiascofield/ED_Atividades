
#include "Set.hpp"

using namespace std;

    StringSet::StringSet(int tamanho){
        this->tamanhoOriginal = tamanho;
        this->tamanhoTabela = tamanho;
        this->tamanhoConjunto = 0;
        this->tabela = new ElementoTabela[tamanho];
        for(int i=0; i < tamanho; i++){
            this->tabela[i].dado = "";
            this->tabela[i].vazio = true;
            this->tabela[i].retirada = false;
        }
    }

    StringSet::~StringSet(){
            delete[] this->tabela;
    }

    void StringSet::Inserir(string s){
        if(!Pertence(s)){
            int valor = Hash(s);
            while(!this->tabela[valor%tamanhoTabela].vazio){
                valor++;
            }

            this->tabela[valor%tamanhoTabela].dado = s;
            this->tabela[valor%tamanhoTabela].vazio = false;
            this->tabela[valor%tamanhoTabela].retirada = false;
            this->tamanhoConjunto++;

            if((this->tamanhoConjunto*2) > this->tamanhoTabela){
                Resize(this->tamanhoTabela*2);
            }
        }   
    }

    void StringSet::Remover(string s){
        if(Pertence(s)){

            int valor = Hash(s);
            while(this->tabela[valor%tamanhoTabela].dado != s){
                valor++;
            }

            this->tabela[valor%tamanhoTabela].dado = "";
            this->tabela[valor%tamanhoTabela].retirada = true;
            this->tabela[valor%tamanhoTabela].vazio = true;
            tamanhoConjunto--;
        }
    }

    bool StringSet::Pertence(string s){
        int valor = Hash(s);

        for(int i = 0; i < tamanhoTabela; i++){
            if(this->tabela[valor%tamanhoTabela].dado == s){
                return true;
            } else if(this->tabela[valor%tamanhoTabela].vazio == true && this->tabela[valor%tamanhoTabela].retirada == false){
                return false;
            }
            valor++;
        }
    }
    
    StringSet* StringSet::Intersecao(StringSet* S){
        StringSet* aux = new StringSet(S->tamanhoTabela);
        for(int i = 0; i < S->tamanhoTabela; i++){
            if(Pertence(S->tabela[i].dado)){
                aux->Inserir(S->tabela[i].dado);
            }
        }
        return aux;
    }

    StringSet* StringSet::Uniao(StringSet* S){
        StringSet* aux;
        
        if(this->tamanhoTabela > S->tamanhoTabela){
            aux = new StringSet(this->tamanhoTabela);
        } else{
            aux = new StringSet(S->tamanhoTabela);
        }

        for(int i = 0; i < this->tamanhoTabela; i++){
            aux->Inserir(this->tabela[i].dado);
        }
        for(int i = 0; i < S->tamanhoTabela; i++){
            aux->Inserir(S->tabela[i].dado);
        }
        return aux;
    }
    StringSet* StringSet::DiferencaSimetrica(StringSet* S){
        StringSet* aux = Intersecao(S);
        StringSet* aux2 = new StringSet(S->tamanhoTabela);

        
        for(int i = 0; i < this->tamanhoTabela; i++){
            if(!(aux->Pertence(this->tabela[i].dado))){
                aux2->Inserir(this->tabela[i].dado);
            }
        }
        for(int i = 0; i < S->tamanhoTabela; i++){
            if(!(aux->Pertence(S->tabela[i].dado))){
                aux2->Inserir(S->tabela[i].dado);
            }
        }
        return aux2;
    }

    void StringSet::Imprimir(){
        string print;
        print += "{ ";
        for(int i = tamanhoTabela-1; i >= 0; i--){
            if(!this->tabela[i].vazio){
                print += this->tabela[i].dado + ", ";
            }
        }
        if(print.size() > 2){
            print.pop_back();
            print.pop_back();
        }
        print += " }";

        for(int i = 0; i < print.size(); i++){
            cout << print[i];
        }
        cout << endl;
    }

    int StringSet::Hash(string s){
        int valor = 0;
        for(int i = 0; i < s.length(); i++){
            switch (s[i]){
                case 'a': valor += 1; break;
                case 'b': valor += 2; break;
                case 'c': valor += 3; break;
                case 'd': valor += 4; break;
                case 'e': valor += 5; break;
                case 'f': valor += 6; break;
                case 'g': valor += 7; break;
                case 'h': valor += 8; break;
                case 'i': valor += 9; break;
                case 'j': valor += 10; break;
                case 'k': valor += 11; break;
                case 'l': valor += 12; break;
                case 'm': valor += 13; break;
                case 'n': valor += 14; break;
                case 'o': valor += 15; break;
                case 'p': valor += 16; break;
                case 'q': valor += 17; break;
                case 'r': valor += 18; break;
                case 's': valor += 19; break;
                case 't': valor += 20; break;
                case 'u': valor += 21; break;
                case 'v': valor += 22; break;
                case 'w': valor += 23; break;
                case 'x': valor += 24; break;
                case 'y': valor += 25; break;
                case 'z': valor += 26; break;
                default: valor += 0; break;
            }
        }
        return valor;
    }
    void StringSet::Rehash(int pos){
        return;
    }
    void StringSet::Resize(size_t tamanho){

        StringSet* aux = new StringSet(tamanho);
        for(int i = 0; i < tamanhoTabela; i++){
            if(!tabela[i].vazio){
                aux->Inserir(this->tabela[i].dado);
            }
        }
        
        delete[] tabela;
        tabela = new ElementoTabela[tamanho]();

        for(int i = 0; i <  tamanho; i++){
            tabela[i] = aux->tabela[i];
        }

        this->tamanhoTabela = tamanho;

        delete aux;
    }

