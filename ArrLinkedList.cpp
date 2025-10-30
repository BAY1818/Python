#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Abstract parent class
class List {
public:
    virtual void insert(int index, int value) = 0;
    virtual void remove(int index) = 0;
    virtual ~List() {}
};

// Array List implementation
class ArrayList : public List {
private:
    int* data;
    int capacity;
    int length;

    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < length; i++) newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    ArrayList(int cap = 10) : capacity(cap), length(0) {
        data = new int[capacity];
    }

    void insert(int index, int value) override {
        if (length >= capacity) resize();
        for (int i = length; i > index; i--) data[i] = data[i - 1];
        data[index] = value;
        length++;
    }

    void remove(int index) override {
        for (int i = index; i < length - 1; i++) data[i] = data[i + 1];
        length--;
    }

    ~ArrayList() { delete[] data; }
};

// Node for Linked List
class Node {
public:
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

// Linked List implementation
class LinkedList : public List {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void insert(int index, int value) override {
        Node* newNode = new Node(value);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void remove(int index) override {
        Node* temp = head;
        if (index == 0) {
            head = head->next;
            delete temp;
        } else {
            for (int i = 0; i < index - 1; i++) temp = temp->next;
            Node* delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
        }
    }

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Test efficiency
void testPerformance(List& list, int n, const string& name) {
    auto start = high_resolution_clock::now();

    for (int i = 0; i < n; i++) list.insert(0, i); // Insert at beginning
    for (int i = 0; i < n; i++) list.remove(0);    // Remove from beginning

    auto end = high_resolution_clock::now();
    cout << name << " took " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
}

int main() {
    int n = 100000; // Test size

    ArrayList arrList;
    LinkedList linkedList;

    testPerformance(arrList, n, "Array List");
    testPerformance(linkedList, n, "Linked List");

    return 0;
}
