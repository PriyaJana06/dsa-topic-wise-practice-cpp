#include<iostream>
#include<vector>
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
        // if(isEmpty()){
        //     cout << "Stack Underflow\n";
        //     return -1;
        // }

        int lastIdx = vec.size()-1;
        return vec[lastIdx];
    }

    bool isEmpty(){   // O(1)
        return vec.size() == 0;
    }
};

int main(){
    Stack<int> s;   // class Template
    Stack<char> s1;  

    // s.push(3);
    // s.push(2);
    // s.push(1);

    // s.pop();
    // s.pop();
    // s.pop();

    s1.push('c');
    s1.push('b');
    s1.push('a');

    // To print Stack Elements:
    cout << "Stack Elements: ";
    while(!s1.isEmpty()){
        cout << s1.top() << " ";
        s1.pop();
    } cout << endl;

    return 0;
}