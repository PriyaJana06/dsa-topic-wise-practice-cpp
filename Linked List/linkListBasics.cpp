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

    // ~Node(){
    //     cout << "~Node\n";
    //     if(next != nullptr){
    //         cout << "Node Destructor for data = " << data << endl; 
    //         delete next;
    //         next = nullptr;
    //     }
    //     cout << "Node deleted data = " << data << "\n";
    // }
};

class List {
    Node* head;
    Node* tail;

public:
    List(){
        head = nullptr;
        tail = nullptr;
    }

    // ~List(){
    //     cout << "~List\n";
    //     if(head != nullptr){
    //         delete head;
    //         head = nullptr;
    //     }
    //     cout << "Linked List deleted\n";
    // }

    // push_front(): TC -> O(1)
    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == nullptr){   // Linked List is empty
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // push_back(): TC -> O(1)
    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == nullptr){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Print Linked List: TC -> O(N)
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
        // Insert at beginning:
        if(pos == 0){
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;

            if(tail == nullptr) tail = newNode;
            return;
        }

        Node* prev = head;
        for(int i = 0; i<pos-1; i++){
            if(prev == nullptr){
                cout << "Position is INVALID\n";
                return;
            }
            prev = prev->next;
        }

        if(prev == nullptr){
            cout << "Invalid Position\n";
            return;
        }

        Node* newNode = new Node(val);

        newNode->next = prev->next;
        prev->next = newNode;

        if(newNode->next == nullptr){
            tail = newNode;
        }
    }

    // pop_front():
    void pop_front(){
        if(head == nullptr){
            cout << "Linked List is EMPTY\n";
            return;
        } 

        Node* temp = head;
        head = head->next;

        // if list became empty
        if(head == nullptr){
            tail = nullptr;
        }
        temp->next = nullptr;
        delete temp;
    }

    //pop_back():  TC -> O(N)
    void pop_back(){
        
        if(head == nullptr){   // empty list
            cout << "Linked List is EMPTY\n";
            return;
        }

        // Single Node
        if(head == tail){
            delete head;
            head = tail = nullptr;
            return;
        }
        
        Node* temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        temp->next = nullptr;
        delete tail;
        tail = temp;
    }

    // Iterative Search: TC -> O(N)
    int searchItr(int key){
        Node* temp = head;
        int idx = 0;

        while(temp != nullptr){
            if(temp->data == key){
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
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

    // pop_front(): 2->100->3->4->5->Null
    // ll.pop_front();
    // ll.printList();

    // pop_back(): 2 -> 100 -> 3 -> 4 -> NULL
    // ll.pop_back();
    // ll.printList();

    // Iterative Search:
    int key = 100;
    cout << "Idx of Key " << key << ": " <<ll.searchItr(key) << endl;

    return 0;
}