#include <iostream>
#include <string>
#include "binarytree.h"
using namespace std;

template<typename T>
int bt_size(BinaryTree<T>& bt){

}

template<typename T>
int bt_height(BinaryTree<T>& bt){

}

template<typename T>
void bt_code(BinaryTree<T>& bt){

}

template<typename T>
void bt_print_code(BinaryTree<T>& bt){
    
}

int main(){
    BinaryTree<int> t34(34);
    BinaryTree<int> t21(21);
    BinaryTree<int> t76(76, t34, t21);
    BinaryTree<int> t55(55);
    BinaryTree<int> bt(1, t76, t55);
    bt_code(bt);
    printf("%d %d\n", bt_size(bt), bt_height(bt));
    bt_print_code(bt);
    //##########################################
    
    BinaryTree<int> bt2(99);
    bt_code(bt2);
    printf("%d %d\n", bt_size(bt2), bt_height(bt2));
    bt_print_code(bt2);
    //##########################################
    
    BinaryTree<int> k11(125), k12(100);
    BinaryTree<int> int1 (50, k11, k12);
    BinaryTree<int> k21(25), k22(75);
    BinaryTree<int> int2 (15, k21, k22);
    BinaryTree<int> bt3(5, int1, int2);
    bt_code(bt3);
    printf("%d %d\n", bt_size(bt3), bt_height(bt3));
    bt_print_code(bt3); 
    
    Node<int>* d11 = new Node<int>(17, nullptr, nullptr);
    Node<int>* intd1 = new Node<int>(25, d11, nullptr);
    Node<int>* intd2 = new Node<int>(39, intd1, nullptr);
    BinaryTree<int> bt4(55);
    bt4.getRoot()->setLeft(intd2);
    bt_code(bt4);
    printf("%d %d\n", bt_size(bt4), bt_height(bt4));
    bt_print_code(bt4);
    //##########################################   
}