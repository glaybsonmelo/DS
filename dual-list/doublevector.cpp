#include "doublevector.h"
#include <iostream>

DoubleVector::DoubleVector(){
  m_capacity = 16;
  m_size = 0;
  m_head = 7;
  m_tail = 8;
  m_list = new int[m_capacity];
};

DoubleVector::DoubleVector(int n) {
    m_capacity = n;
    m_size = 0;
    m_head = (m_capacity - 1) / 2;
    m_tail = m_head + 1;
    m_list = new int[m_capacity];
}

DoubleVector::~DoubleVector(){
  delete[] m_list;
}

int DoubleVector::size(){
  return m_size;
}

bool DoubleVector::empty(){
  return m_size == 0;
}

void DoubleVector::push_back(int value) {
  if(m_tail == m_capacity){
    int qty_zeros = m_capacity - m_size;
    for(int i = 0; i < qty_zeros/2+1; i++){
      left_shift();
    }
  }
  if(m_size == m_capacity){
    resize();
  }
  m_list[m_tail] = value;

  m_tail++;
  m_size++;
}

void DoubleVector::push_front(int value){
  if(m_head == 0){
    // caso exista espaço livre na direita, metade dele irá para o lado esquerdo.
    int freeSpaceCountRight = m_capacity - m_tail;
    for(int i = 0; i < (freeSpaceCountRight/2+1); i++){
      right_shift();
    }
  }
  // caso nao tenha espaço livre na esquerda e direita, o espaço total será duplicado
  if(m_size == m_capacity){
    resize();
  }
  m_list[m_head] = value;
  m_head --;
  m_size ++;
}

int DoubleVector::at(int k) {
  return m_list[m_head + k + 1];
}

int DoubleVector::pop_back(){
    if(empty()){
      return - 1;
    }
    int removedItem = m_list[m_tail];
    m_tail--;
    m_size--;
    return removedItem;
}

// Redimensiona o vetor dinâmico duplicando sua capacidade.
void DoubleVector::resize() {
    m_capacity = m_capacity * 2;

    // criar um novo vetor com a nova capacidade
    int* m_list_temp = m_list;
    m_list = new int[m_capacity];

    // determinar o novo índice inicial
    int newIndex = m_capacity / 4;

    // atualizar o índice do final da lista
    m_tail = m_head + m_size - 1;

    // copiar os elementos do vetor antigo para o novo vetor
    for (int i = 0; i <= m_tail; i++) {
        m_list[newIndex++] = m_list_temp[m_head + i];
    }
}

int DoubleVector::pop_front(){
  if(empty()){
    return - 1;
  }
  int removedItem = m_list[m_head];
  m_head++;
  m_size--;
  return removedItem;
};

void DoubleVector::left_shift() {
    for (int i = m_head ; i <= m_tail; i++) {
        m_list[i - 1] = m_list[i];
    }
    m_head--;
    m_tail--;
}

void DoubleVector::right_shift(){
    for (int i = m_tail +1; i > m_head; i--) {
        m_list[i] = m_list[i-1];
    }
    m_head++;
    m_tail++;
}

// Remove o valor presente no indice k
void DoubleVector::remove(int k){
  if (k >= 0 && k < m_size) {

    // checa a quantidade de espaços livres no inicio e fim
    int freeInRight = m_capacity - m_tail;
    int freeInLeft = m_head + 1;

    if (freeInLeft < freeInRight) {
        // desloca para a esquerda, do fim da lista ate k
        for (int i = m_tail; i > k; i--) {
            m_list[i - 1] = m_list[i];
        }
        m_tail++;
    }
    else {
        // desloca para a direita, do inicio da lista ate k
        for (int i = k; i > m_head; i--) {
            m_list[i] = m_list[i-1];
        }
        m_head++;
    }

    m_size--;
    }
};

void DoubleVector::removeAll(int value){
  for(int i = m_head; i != m_tail; i++){
    if(m_list[i] == value){
      remove(i);
    }
  }
}

void DoubleVector::printAll(){
  for(int i = 0; i < m_capacity; i++){
    std::cout << m_list[i] << ' ';
  }
  std::cout << '\n';
}

void DoubleVector::print(){
  for(int i = m_head + 1; i < m_size; i++){
    std::cout << m_list[i] << ' ';
  }
  std::cout << '\n';
};

void DoubleVector::printReverse(){
  for(int i = m_tail - 1; i != m_head; i--){
    std::cout << m_list[i] << ' ';
  }
  std::cout << '\n';
};

void DoubleVector::replaceAt(int value, int k){
  if(k >= 0 && k <= m_size -1)
    m_list[m_head + k] = value;
}

void DoubleVector::insert(int value, int k){
  int freeInRight = m_capacity - m_tail;
  int freeInLeft = m_head + 1;
  if(freeInLeft < freeInRight){
    m_list[m_head + k] = value;
    left_shift();
  }
  else {
    m_list[m_head + k] = value;
    right_shift();
  }
}

void DoubleVector::concat(DoubleVector& lst){
  
}

bool DoubleVector::equal(DoubleVector& lst){
  return true;
}