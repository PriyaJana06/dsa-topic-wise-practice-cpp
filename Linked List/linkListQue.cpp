#include<iostream>
// #include<list>
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

    // Que: Find & Remove Nth Node from End: TC = O(N) ; SC = O(1)
    int getSize(){
        int sz = 0;
        Node* temp = head;

        while(temp != nullptr){
            temp = temp->next;
            sz++;
        }
        return sz;
    }

    void removeNth(int n){
        Node* prev = head;
        int size = getSize();

        for(int i=1; i<(size-n); i++){  // i = size-n => prev => node's prev
            prev = prev->next;
        }
        
        Node* toDel = prev->next;
        cout << "going to delete: " << toDel->data << endl;
        prev->next = prev->next->next;  // deletes nth node from end

        delete toDel;
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
    // cout << "Reversed Linked List: ";
    // ll.reverse();
    // ll.printList();

    // Que: Find & Remove Nth Node from End:
    int n = 2;
    ll.removeNth(n);
    ll.printList();


    return 0;
}