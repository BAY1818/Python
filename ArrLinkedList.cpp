#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


//Abstract parent class
class List{
    public:
        virtual void insert(int index, int value) = 0;
        virtual void remove(int index) = 0;
        virtual int get(int index) = 0;
        virtual int size() = 0;
        virtual ~List() {}
};

class ArrayList : public List{
    private:
        int* data;
        int capacity;
        int length;

        void resize(){
            capacity *= 2;
            int* newData = new int[capacity];
            for(int i = 0; i < length; i++) newData[i] = data[i];
            delete[] data;
            data = newData;
            
    }
    public:
        ArrayList(int cap = 10) : capacity(cap), length(0){
            data = new int[capacity];
        }
        
        void insert(int index, int value) override {
            if(length >= capacity) resize();
            for (int i = length; i > index; i--) data [i] = data[i - 1];
            data[index] = value;
            length++;
            
        }

        void remove(int index)override{
            for(int i = index; i < length - 1; ++i) data[i] = data[i+1];
            length--;
        }

        int get(int index)override{
            return data[index];
        }

        int size()override{
            return length;
        }

        ~ArrayList(){
            delete[] data;
        }
};

class Node {
    public:
        int val;
        Node* next;

        Node(int v) : val(v), next(nullptr){}
};

class LinkedList : List {
    private:
        Node* head;
        int length;
    public:
        LinkedList() : head(nullptr), length(0){}

        void insert(int index, int value) override{
            Node* newNode = new Node(value);
            if(index == 0){
                newNode->next = head;
                head = newNode;
            }
            else{
                Node* temp = head;
                for (int i = 0; i < index - 1; i++) temp = temp->next;
                newNode->next = temp->next;
                temp->next = newNode;
            }
            ++length;
        }
        void remove(int index)override{
            Node* temp = head;
            if (index == 0) {
                head = head->next;
                delete temp;
            }
            else{
                for(int i = 0; i < index - 1; i++)temp = temp->next;
                Node* delNode = temp->next;
                temp->next = delNode->next;
                delete delNode;
            }
            length--;
        }
};

