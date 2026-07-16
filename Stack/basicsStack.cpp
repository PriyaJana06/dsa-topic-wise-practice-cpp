#include<iostream>
#include<vector>
using namespace std;

// Implementation of Stack using Vector:
class Stack{
    vector<int> vec;
public:
    void push(int val){  // O(1)
        vec.push_back(val);
    }

    void pop(){    // O(1)
        if(isEmpty()){
            cout << "Stack Underflow\n";
            return;
        }
        vec.pop_back();
    }

    int top(){    // O(1)
        if(isEmpty()){
            cout << "Stack Underflow\n";
            return -1;
        }

        int lastIdx = vec.size()-1;
        return vec[lastIdx];
    }

    bool isEmpty(){   // O(1)
        return vec.size() == 0;
    }
};

int main(){
    Stack s;

    s.push(3);
    s.push(2);
    s.push(1);

    // To print Stack Elements:
    cout << "Stack Elements: ";
    while(!s.isEmpty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}