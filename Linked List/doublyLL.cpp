#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
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
    Node* push_front(int val){
        Node* newNode = new Node(val);

        if(head == nullptr){
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return head;
    }

    // pop_front():
    void pop_front(){
        if(head == nullptr){
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        
        if(head != nullptr){
            head->prev = nullptr;
        } else {
            tail = nullptr;  // list became empty
        }

        temp->next = nullptr;
        delete temp;
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

    // pop_front():
    dbll.pop_front();
    dbll.printList();

    dbll.pop_front();
    dbll.printList();

    dbll.pop_front();
    dbll.printList();

    dbll.pop_front();
    dbll.printList();

    dbll.pop_front();
    


    return 0;
}