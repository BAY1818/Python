#include <iostream>
using namespace std;

template <typename E>
class Node {
    public:
        E data;
        Node* next;

        Node(E val) : data(val), next(nullptr){}        
};

template <typename E>
class LinkedList{
    private:
        Node<E>* head;

    public:
        LinkedList() : head(nullptr) {}

        void insert(E val){
            Node<E>* newNode = new Node<E>(val);
            newNode->next = head;
            head = newNode;
        }
}