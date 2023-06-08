#ifndef DOUBLEVECTOR_H
#define DOUBLEVECTOR_H

class DoubleVector {
  private:
    int*m_list {nullptr}; // ponteiro para a lista
    int m_size {0};       // numero de elementos na lista
    int m_capacity {0};   // capacidade total da lista
    int m_head;           // indice do inicio da lista  
    int m_tail;           // incide do final da lista

  public:

  //Construtor da classe. Deve iniciar todos os atributos da classe
  //de acordo com a descricao acima da lista
    DoubleVector();

  // Construtor da classe. Aloca o vetor com capacidade n,
  //deixando espacos disponıveis na frente e atras iguais.
    DoubleVector(int n);

 //Destrutor da classe. Libera mem´oria previamente alocada.
    ~DoubleVector();

  //Retorna o numero de elementos na lista.
    int size();

    //Retorna true se a lista estiver vazia e false caso contrario.
    bool empty();

    /*Insere o inteiro value ao final da lista.*/
    void push_back(int value);

    /* Retorna o elemento da lista de ındice k (Cuidado, é o índice da
    lista e nao do vetor). A funcao verifica se k esta dentro dos limites de elementos
    validos. Caso contrario, retorna -1. Obrigatoriamente deve ser O(1).*/
    int at(int k);

    /*Remove elemento do final da lista e retorna seu valor.*/
    int pop_back();

    /*Insere o inteiro value no inicio da lista.*/
    void push_front(int value);


    void replaceAt(int value, int k);
    // /* Remove elemento do inicio da lista e retorna seu valor.*/
    // int pop_front();

    // /* Realiza o deslocamento completo, seja para a direita ou esquerda,
    // de acordo a descricao na Secao 1.1.1. Caso desejem, podem dividir em duas funcoes
    // lef t shif t e right shif t*/
    // void shift();

    /* Realiza o redimensionamento, de acordo a descricao na Secao 1.2.*/
    void rezise();

    // /*Remove o elemento de ındice k da lista (Cuidado, e o ındice
    // da lista e nao do vetor) de acordo a descricao na Secao 1.1.2. A ordem dos demais
    // elementos da lista devem se manter.*/
    // void remove(int k); 

    // /* Remove da lista todas as ocorrencias de value. A
    // ordem dos demais elementos da lista entre se devem se manter.*/
    // void removeAll(int value);

    // /*Imprime os elementos da lista.*/
    // void print(); 

    // /*Imprime os elementos da lista em ordem reversa.*/
    // void printReverse(); 

    // /*Concatena a lista atual com a lista lst passada por parˆametro. A lista lst nao e modificada nessa opera¸c˜ao. Os elementos de
    // lst serao adicionados na ordem no final da lista do objeto da funcao.*/
    // void concat(DoubleVector& lst); 
    
    // /*Determina se a lista passada por parametro e
    // igual a lista em quest˜ao. Duas listas sao iguais se elas possuem o mesmo tamanho
    // e o valor do k-esimo elemento da primeira lista e igual ao k-esimo elemento da
    // segunda lista.*/
    // bool equal(DoubleVector& lst); 
};

#endif