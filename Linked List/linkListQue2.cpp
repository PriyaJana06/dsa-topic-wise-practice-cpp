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
public:
    Node* head;
    Node* tail;

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

    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == nullptr){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Que: Reverse a Linked List:
    Node* reverse(Node* head){
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

        return prev;
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

// IMP: Que: Merge Sort on LL:
    Node* splitAtMid(Node* head){
        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;

        while(fast != nullptr && fast->next != nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Single Node:
        if(prev != nullptr){
            prev->next = nullptr;  // split at middle
        }
        
        return slow;   // slow = rightHead
    }

    Node* mergeLL(Node* left, Node* right){
        List ans;  
        Node* i = left;
        Node* j = right;

        while(i != nullptr && j != nullptr){
            if(i->data <= j->data){
                ans.push_back(i->data);
                i = i->next;
            } else {
                ans.push_back(j->data);
                j = j->next;
            }
        }

        while(i != nullptr){
            ans.push_back(i->data);
            i = i->next;
        }

        while(j != nullptr){
            ans.push_back(j->data);
            j = j->next;
        }

        return ans.head;
    }

    Node* mergeSortLL(Node* head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        Node* rightHead = splitAtMid(head);

        Node* left = mergeSortLL(head);  // left head
        Node* right = mergeSortLL(rightHead);  // right head

        return mergeLL(left, right);   // head of sorted Linked list
    }

    // Que: Zig-Zag Linked List:
    Node* zigZagLL(Node* head){

        if(head == nullptr || head->next == nullptr){
            return head;
        }

        Node* rightHead = splitAtMid(head);
        Node* rightHeadRev = reverse(rightHead);

        // alternate merging: 1st head = head; 2nd head = rightHeadRev
        Node* left = head;
        Node* right = rightHeadRev;
        Node* tail = right;

        while(left != nullptr && right != nullptr){
            Node* nextLeft = left->next;
            Node* nextRight = right->next;

            left->next = right;
            right->next = nextLeft;
            tail = right;

            left = nextLeft;
            right = nextRight;
        }

        if(right != nullptr){
            tail->next = right;
        }
        return head;
    }
};


int main(){
    List ll;

    // Que: Merge 2 Sorted LL:
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    ll.printList();

    cout << "Merge Sort Linked List: ";
    ll.head = ll.mergeSortLL(ll.head);
    ll.printList();

    // Que: Zig-Zag Linked List:
    cout << "Zig-Zag List: ";
    ll.head = ll.zigZagLL(ll.head);
    ll.printList();
    
    return 0;
}