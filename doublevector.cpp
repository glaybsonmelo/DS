#include "doublevector.h"
#include <iostream>

DoubleVector::DoubleVector(){
  m_capacity = 16;
  m_size = 0;
  m_head = 7;
  m_tail = 8;
  m_list = new int[m_capacity];
};

// Construtor da classe. Aloca o vetor com capacidade n,
//deixando espacos disponıveis na frente e atras iguais.
DoubleVector::DoubleVector(int n) {
    m_capacity = n;
    m_size = 0;
    m_head = (m_capacity - 1) / 2;
    m_tail = m_head + 1;
    m_list = new int[m_capacity];
}


//Destrutor da classe. Libera mem´oria previamente alocada.
DoubleVector::~DoubleVector(){
  delete[] m_list;
}

//Retorna o numero de elementos na lista.
int DoubleVector::size(){
  return m_size;
}

//Retorna true se a lista estiver vazia e false caso contrario.
bool DoubleVector::empty(){
  return m_size == 0;
}

void DoubleVector::push_back(int value) {
    m_list[m_tail] = value;
    // std::cout << "put " << value << "in " << m_tail << '\n';
    // m_tail = (m_tail + 1) % m_capacity;
    m_tail++;
    m_size++;
}


/* Retorna o elemento da lista de ındice k (Cuidado, é o índice da
lista e nao do vetor). A funcao verifica se k esta dentro dos limites de elementos
validos. Caso contrario, retorna -1. Obrigatoriamente deve ser O(1).*/
int DoubleVector::at(int k) {
  // return m_list[(m_head + k) % m_capacity];
  return m_list[m_head + k + 1];
}


/*Remove elemento do final da lista e retorna seu valor.*/
int DoubleVector::pop_back(){
  // Lista vazia, não há elemento para remover
  if (m_size == 0) {
    return -1;
    }

    // m_tail = (m_tail - 1 + m_capacity) % m_capacity;
    m_tail ++;
    int removedItem = m_list[m_tail];
    m_size--;

    return removedItem;
}

void DoubleVector::replaceAt(int value, int k){}



/* Realiza o redimensionamento, de acordo a descricao na Secao 1.2.*/
void DoubleVector::rezise(){
  
}