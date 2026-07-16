#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        prev = next = nullptr;
    }
};

class DoublyList{
public:
    Node* head;
    Node* tail;

    DoublyList(){
        head = tail = nullptr;
    }

    // push_front(val):
    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == nullptr){
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

// To print Doubly List:
    void printList(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " <==> ";
            temp = temp->next;
        }
        cout << "null\n";
    }
};

int main(){
    DoublyList dbll;

    // push_front(val):
    dbll.push_front(4);
    dbll.push_front(3);
    dbll.push_front(2);
    dbll.push_front(1);

    // To print List:
    dbll.printList();

    return 0;
}