#include<iostream>
#include<stack>
using namespace std;

// Push At Bottom of Stack:
void pushAtBottom(stack<int> &s, int val){  // TC = O(N)
    if(s.empty()){
        s.push(val);   // push at top = push at bottom
        return;
    }
    int temp = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(temp);
}

int main(){
    // Push At Bottom of Stack:
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);
    pushAtBottom(s, 4);

    cout << "Stack Elements: ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }cout << endl;

    return 0;
}