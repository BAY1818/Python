#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = nullptr;
        }
};

class LinkedList{
    private:
        Node* head;

    public:
        LinkedList() {head = nullptr;}

    void insertEnd(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void printList(){
        Node* temp = head;
        while(temp){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};


int main (){
    LinkedList list;
    list.insertEnd(10);
    list.insertEnd(2000);

    list.printList();
    return 0;
}