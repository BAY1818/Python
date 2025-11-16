#ifndef LINKSTACK_H
#define LINKSTACK_H

#include "Stack.h"
#include <iostream>
using namespace std;

template <typename E>
class LinkedStack : public Stack<E> {
private:
    struct Node {
        E data;
        Node* next;
        Node(const E& d, Node* n = nullptr) : data(d), next(n) {}
    };

    Node* topNode;
    int count;

public:
    LinkedStack() : topNode(nullptr), count(0) {}

    ~LinkedStack() {
        clear();
    }

    void clear() override {
        while (topNode) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
        count = 0;
    }

    void push(const E& it) override {
        topNode = new Node(it, topNode);
        count++;
    }

    E pop() override {
        if (!topNode) {
            cerr << "Stack Underflow\n";
            exit(1);
        }
        Node* temp = topNode;
        E value = temp->data;
        topNode = topNode->next;
        delete temp;
        count--;
        return value;
    }

    const E& topValue() const override {
        if (!topNode) {
            cerr << "Stack Empty\n";
            exit(1);
        }
        return topNode->data;
    }

    int length() const override {
        return count;
    }
};

#endif
