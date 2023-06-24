#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "node.h"

template<typename T>
class BinaryTree {
private:
    Node<T>* root; // Ponteiro para o nó raiz da árvore binária
    
public:
    //Construtor de uma árvore binária vazia
    BinaryTree(); 
    
    //Construtor de uma arvore com o valor do nó raiz
    BinaryTree(T value);    
    
    //Construtor de uma árvore binária com o valor do nó raiz  
    //e as duas sub-árvores esquerda e direita, respectivamente.
    BinaryTree(T value, BinaryTree<T>& l, BinaryTree<T>& r);
    
    //Retorna o nó raiz
    Node<T>* getRoot();
    
    //Atualiza o nó raiz
    void setRoot(Node<T>* newRoot);
    
    //Retorna true se e somente se a árvore estiver vazia
    bool is_empty();
    
    //Retorna true se e somente se a árvore é uma folha
    bool is_leaf();
    
    //Verifica se um determinado valor está contido na árvore
    bool contains(T value);
    
    //Imprime todos os valores armazenado na árvore
    void print_values();
    
    //Remove todos os elementos da árvore, ou seja, deixa a árvore vazia
    void clear();

    // XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx

    //Calcula o numero de nós da árvore 
    int bt_size(BinaryTree<T>& bt);

    //Preenche o campo code de cada nó com o código do nó
    void bt_code(BinaryTree<T>& bt);

    // Imprime o código da raiz, depois imprime todos os
    // os códigos da subárvore esquerda e 
    // depois imprime todos os os códigos da subárvore direita
    void bt_print_code(BinaryTree<T>& bt);
  
    // destrutor: libera memoria alocada
    ~BinaryTree();

};

#include "binarytree.cpp"
#endif