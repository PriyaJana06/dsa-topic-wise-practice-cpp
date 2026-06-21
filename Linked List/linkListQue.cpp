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


    // Que: Detect Cycle/loop in Linked List: TC = O(N)
    bool hasCycle(Node* head){
        Node* slow = head;
        Node* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;   // +1
            fast = fast->next->next;   // +2

            if(fast == slow){   // Floyd's Cycle Finding Algorithm
                cout << "Cycle Exists\n";
                return true;
            }
        }
        cout << "Cycle doesn't exists\n";
        return false;
    }

    
    // Que: Removing Cycle in a LList:
    void removeCycle(Node* head){
        // to detect cycle:
        Node* slow = head;
        Node* fast = head;
        bool isCycle = false;
        
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                cout << "Cycle Exists\n";
                isCycle = true;
                break;
            }
        }

        if(!isCycle){
            cout << "Cycle doesn't exists\n";
            return;
        }

        slow = head;
        // special case: tail -> head
        if(slow == fast){
            while(fast->next != slow){
                fast = fast->next;
            }
            fast->next = nullptr;
        } else{    // Normal case
            Node* prev = fast;
            while(slow != fast){
                slow = slow->next;
                fast = prev;
                fast = fast->next;
            }
            prev->next = nullptr;   // remove cycle
        }
    }

    // Que: Merge Sort on LL:

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

    Node* merge(Node* left, Node* right){
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

        Node* rightHead = sliptAtMid(head);

        Node* left = mergeSortLL(head);  // left head
        Node* right = mergeSortLL(rightHead);  // right head

        return merge(left, right);   // head of sorted Linked list
    }
};

int main(){
    List ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    // ll.printList();

    // Que: Reverse a Linked List:
    cout << "Reversed Linked List: ";
    ll.reverse();
    ll.printList();


    // Que: Find & Remove Nth Node from End:
    int n = 2;
    ll.removeNth(n);
    ll.printList();


    // Que: Detect Cycle/Loop in Linked List: 1->2->3->4->5->1
    ll.tail->next = ll.head;     // LList with cycle: 1->2->3->4->5->1
    // ll.hasCycle(ll.head);
    // ll.printList();  // can't print because linked list has cycle(infinitely runs)


    // Que: Removing Cycle in a LList:
    ll.removeCycle(ll.head);
    ll.printList();

    // Que: Merge 2 Sorted LL:





    return 0;
}