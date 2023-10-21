
class No{
    public:
    int valor_;
    No* proximo_;

    No () {}

    No(int valor){
        valor_ = valor;
        proximo_ = nullptr;
    }

    No(int valor, No* proximo){
        valor_ = valor;
        proximo_ = proximo;
    }
};