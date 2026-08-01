#include<iostream>
using namespace std;

// Implementation of Queue using Linked List:
class Node{
public: 
    int data;
    Node* next;

    Node(int val){
        data = val;
        this->next = nullptr;
    }
};

class Queue{
    Node* head;
    Node* tail;
public:
    Queue(){
        head = tail = nullptr;
    }

    void printQueue(){
        if(head == nullptr){
            cout << "Queue is Empty\n";
            return;
        }

        Node* temp = head;
        cout << "Queue elements: ";
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        } cout << endl;
    }

    void push(int val){  //TC = O(1)
        Node* newNode = new Node(val);

        if(head == nullptr){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop(){   // TC = O(1)
        if(empty()){
            cout << "Queue is Empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if(head == nullptr){
            tail = nullptr;
        }
        temp->next = nullptr;
        delete temp;
    }

    int front(){    // TC = O(1)
        if(empty()){
            cout << "Queue is Empty\n";
            return -1;
        }
        return head->data;
    }

    bool empty(){   // TC = O(1)
        return head == nullptr;
    }
};

int main(){
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.printQueue();  // 1 2 3

    return 0;
}