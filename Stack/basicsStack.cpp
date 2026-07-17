#include<iostream>
#include<vector>
#include<list>
#include<stack>  // stack STL
using namespace std;

// Implementation of Stack using Vector with class Template:
template<class T>  // class template
class Stack{
    vector<T> vec;

public:
    void push(T val){  // O(1)
        vec.push_back(val);
    }

    void pop(){    // O(1)
        if(isEmpty()){
            cout << "Stack Underflow\n";
            return;
        }
        vec.pop_back();
    }

    T top(){    // O(1)
        if(isEmpty()){
            cout << "Stack is empty\n";
        }
        int lastIdx = vec.size()-1;
        return vec[lastIdx];
    }

    bool isEmpty(){   // O(1)
        return vec.size() == 0;
    }
};

// Implementation of Stack using Linked List (STL):
template<class T>
class Stack2 {
public:
    list<T> ll;   // STL Linked List

    void push(T val){
        ll.push_front(val);
    }

    void pop(){
        if(isEmpty()){
            cout << "Stack Underflow\n";
            return;
        }
        ll.pop_front();
    }

    T top(){
        if(isEmpty()){
            cout << "Stack is Empty\n";
        }
        return ll.front();
    }

    bool isEmpty(){
        return ll.size() == 0;
    }
};

// Implementation of Stack using Linked list only:
template<class T>
class Node{
public:
    T data;
    Node<T>* next;

    Node(T val){
        data = val;
        next = nullptr;
    }
};

template<class T>
class Stack3{
public:
    Node<T>* head;

    Stack3(){    // when new stack is created head = nullptr
        head = nullptr;
    }

    void push(T val){
        Node<T>* newNode = new Node<T>(val);

        if(head == nullptr){
            head = newNode;
        } else {
            newNode->next = head;
            head= newNode;
        }
    }

    void pop(){
        if(head == nullptr){
            cout << "Stack Underflow\n";
            return;
        } 
        Node<T>* temp = head;
        head = head->next;
        temp->next = nullptr;

        delete temp;
    }

    T top(){
        if(isEmpty()){
            cout << "Stack is empty\n";
        }
        return head->data;
    }

    bool isEmpty(){
        return head == nullptr; 
    }
};

int main(){
    //// Implementation of stack using vector:
    Stack<int> s;   // class Template

    s.push(3);
    s.push(2);
    s.push(1);

    // To print Stack Elements:
    cout << "Stack Elements: ";
    while(!s.isEmpty()){
        cout << s.top() << " ";
        s.pop();
    } cout << endl;


    //// Implementation of Stack using linked list(STL) :
    Stack2<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << "Top of Stack: " << s1.top() << endl;

    while(!s1.isEmpty()){
        cout << s1.top() << " ";
        s1.pop();
    } cout << endl;

    //// Implementation of Stack using linked list only:
    Stack3<int> s2;
    s2.push(100);
    s2.push(200);
    s2.push(300);

    cout << "Top of Stack: " << s2.top() << endl;

    while(!s2.isEmpty()){
        cout << s2.top() << " ";
        s2.pop();
    } cout << endl;


    // Stack STL:
    stack<char> stack;
    
    stack.push('a');
    stack.push('b');
    stack.push('c');

    cout << "Char in Stack: ";
    while(!stack.empty()){
        cout << stack.top() << " ";
        stack.pop();
    }cout << endl;

    return 0;
}