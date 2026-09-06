#include<iostream>
#include<stack>
#include<queue>
using namespace std;

//Que: Implement Queue using 2 Stack:
class Queue{  // FIFO 
    stack<int> s1;
    stack<int> s2;
public:
    void push(int data){  // O(N)
        // s1 -> s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(data);

        // s2 -> s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop(){  // O(1)
        s1.pop();
    }

    int front(){   // O(1)
        return s1.top();
    }

    bool empty(){
        return s1.empty();
    }
};

//Que: Implement Stack using 2 Queues:
class Stack{
    queue<int> q1;
    queue<int> q2;
public:
    void push(int data){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(data);

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop(){
        q1.pop();
    }

    int top(){
        return q1.front();
    }

    bool empty(){
        return q1.empty();
    }
};

int main(){

    //Que: queue using 2 stacks:
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "Queue using 2 Stacks: ";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    } cout << endl;

    //Que: Stack using 2 Queues:
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Stack using 2 Queues: ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}