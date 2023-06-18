
#ifndef STACK_CPP
#define STACK_CPP

#include <istream>
#include <iostream>
#include <string>
#include "stack.h"
// Implementação dos métodos da classe Stack

template<typename T>
Stack<T>::Stack() {
    m_top = nullptr;
    m_size = 0;
}

template<typename T>
Stack<T>::~Stack() {
    clear();
}

template<typename T>
int Stack<T>::size() {
    return m_size;
}

template<typename T>
bool Stack<T>::empty() {
    return m_size == 0;
}

template<typename T>
void Stack<T>::clear() {
    while (m_top != nullptr) {
        Node<T>* temp = m_top;
        m_top = m_top->getNext();
        delete temp;
    }
    m_size = 0;
}

template<typename T>
void Stack<T>::push(T value) {
    Node<T>* newNode = new Node<T>(value, m_top);
    m_top = newNode;
    m_size++;
}

template<typename T>
T Stack<T>::pop() {
    if (empty()) {
        throw std::runtime_error("Empty stack.");
    }

    T value = m_top->getValue();
    Node<T>* temp = m_top;
    m_top = m_top->getNext();
    delete temp;
    m_size--;

    return value;
}

template<typename T>
T Stack<T>::top() {
    if (empty()) {
        throw std::runtime_error("Empty stack.");
    }

    return m_top->getValue();
}

#endif