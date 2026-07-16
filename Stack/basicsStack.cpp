#include<iostream>
#include<vector>
#include<list>
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
            cout << "Stack Underflow\n";
        }

        int lastIdx = vec.size()-1;
        return vec[lastIdx];
    }

    bool isEmpty(){   // O(1)
        return vec.size() == 0;
    }
};

// Implementation of Stack using Linked List STL:
template<class T>
class Stack2 {
    list<T> ll;

public:
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


    //// Implementation of Stack using linked list(STL):
    Stack2<int> s1;
    s1.push(4);
    s1.push(3);
    s1.push(2);

    while(!s1.isEmpty()){
        cout << s1.top() << " ";
        s1.pop();
    } cout << endl;

    return 0;
}