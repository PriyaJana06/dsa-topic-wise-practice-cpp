#include<iostream>
using namespace std;

// Basic structure of creating LL:
class Node {
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }

    ~Node(){
        cout << "~Node\n";
        if(next != nullptr){
            cout << "Node Destructor for data = " << data << endl; 
            delete next;
            next = nullptr;
        }
        cout << "Node deleted data = " << data << "\n";
    }
};

class List {
    Node* head;
    Node* tail;

public:
    List(){
        head = nullptr;
        tail = nullptr;
    }

    ~List(){
        cout << "~List\n";
        if(head != nullptr){
            delete head;
            head = nullptr;
        }
        cout << "Linked List deleted\n";
    }

    // push_front():
    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == nullptr){   // Linked List is empty
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // push_back():
    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == nullptr){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Print Linked List:
    void printList(){
        Node* temp = head;

        while(temp != nullptr){
            cout << temp->data << " -> ";
            temp = temp->next;
        } 
        cout << "NULL" << "\n";

        delete temp;
    }

    // Insert in middle of LL:
    void insert(int val, int pos){
        Node* newNode = new Node(val);

        Node* prev = head;
        for(int i = 0; i<pos-1; i++){
            if(prev == nullptr){
                cout << "Position is INVALID\n";
                return;
            }
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }
};

int main(){
    List ll;

    // push_front(val): 1->2->3->Null 
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();

    // push_back(val): 1->2->3->4->Null
    ll.push_back(4);
    ll.push_back(5);
    ll.printList();

    // Insert in Middle of ll:
    ll.insert(100, 2);
    ll.printList(); 

    return 0;
}