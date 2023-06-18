
#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "queue.h"
#include <cstddef>
#include <utility>
#include <iostream>


    template<typename T>
    // construtor: cria uma fila vazia
    Queue<T>::Queue(): m_first(nullptr), m_last(nullptr) {
      m_size = 0;
    }

    // construtor de cópia. A fila lst deve se manter com os mesmo valores.
    template<typename T>
    Queue<T>::Queue(Queue<T>& lst) {
        m_first = nullptr;
        m_last = nullptr;
        m_size = 0;

        // Copia os elementos da fila lst para a nova fila
        Node<T>* current = lst.m_first;
        while (current != nullptr) {
            push(current->getValue());
            current = current->getNext();
        }
    }
    
    // destrutor: libera memoria alocada
    template<typename T>
    Queue<T>::~Queue(){
      clear();
    }

    // retorna o numero de elementos na fila
    template<typename T>
    int Queue<T>::size(){
      return m_size;
    }
    
    // Retorna true se e somente se a fila estiver vazia
    template<typename T>
    bool Queue<T>::empty(){
      return m_size == 0;
    }

    // Remove todos os elementos da fila, ou seja, deixa a fila vazia
    template<typename T>
    void Queue<T>::clear(){
      while(m_last != nullptr) {

      }
    }

    //Insere no final da fila
    template<typename T>
    void Queue<T>::push(T value){
      Node<T>* newNode = new Node<T>(value, nullptr);
      if (m_last == nullptr) {
          m_first = newNode;
          m_last = newNode;
      } else {
          m_last->setNext(newNode);
          m_last = newNode;
      }
      m_size++;
    } 

    // Remove e retorna o primeiro elemento da fila.
    // Se a fila estiver vazia lança a exceção throw std :: runtime_error("Empty queue.")
    template<typename T>
    T Queue<T>::pop() {
      if (empty()) {
            throw std::runtime_error("Empty queue.");
        }

        Node<T>* temp = m_first;
        T value = temp->getValue();

        m_first = m_first->getNext();
        delete temp;

        if (m_first == nullptr) {
            m_last = nullptr;
        }

        m_size--;

        return value;
    }

#endif