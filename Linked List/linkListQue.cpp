#include<iostream>
#include<list>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class List {
    // Private Properties:
    Node* head;
    Node* tail;

public:
    List(){
        head = nullptr;
        tail = nullptr;
    }

    void printList(){
        Node* temp = head;

        while(temp != nullptr){
            cout << temp->data << " -> ";
            temp = temp->next;
        } 
        cout << "NULL" << "\n";

        delete temp;
    }

    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == nullptr){   // Linked List is empty
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Que: Reverse a Linked List:
    void reverse(){
        Node* curr = head;
        Node* prev = nullptr;
        tail = head;  // old head will become new tail

        while(curr != nullptr){
            Node *next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        head = prev;  // new head
    }
};

int main(){
    List ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();

    // Que: Reverse a Linked List:
    cout << "Reversed Linked List: ";
    ll.reverse();
    ll.printList();



    


    return 0;
}