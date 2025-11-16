#ifndef ARRSTACK_H
#define ARRSTACK_H

#include "Stack.h"
#include <iostream>
using namespace std;

template <typename E>
class ArrayStack : public Stack<E> {
private:
    int maxSize;
    int topIndex;
    E* stackArray;

public:
    ArrayStack(int size = 1000) {
        maxSize = size;
        topIndex = 0;
        stackArray = new E[maxSize];
    }

    ~ArrayStack() {
        delete[] stackArray;
    }

    void clear() override {
        topIndex = 0;
    }

    void push(const E& it) override {
        if (topIndex >= maxSize) {
            cerr << "Stack Overflow\n";
            exit(1);
        }
        stackArray[topIndex++] = it;
    }

    E pop() override {
        if (topIndex == 0) {
            cerr << "Stack Underflow\n";
            exit(1);
        }
        return stackArray[--topIndex];
    }

    const E& topValue() const override {
        if (topIndex == 0) {
            cerr << "Stack Empty\n";
            exit(1);
        }
        return stackArray[topIndex - 1];
    }

    int length() const override {
        return topIndex;
    }
};

#endif
