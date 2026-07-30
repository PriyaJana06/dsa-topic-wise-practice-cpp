#include<iostream>
#include<stack>
#include<string>
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

// Reverse a string using stack:  TC = O(n) , n = size of string 
string reverseString(string str){   // SC = O(n)
    string ans;
    stack<char> s;
    
    for(int i=0; i<str.size(); i++){  // push whole str in stack
        s.push(str[i]);
    }

    while(!s.empty()){    // pop str in reverse order
        char top = s.top();
        ans += top;
        s.pop();
    }
    return ans;
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

    //Que: Reverse a string using stack:
    string str = "priyanka";
    cout << "Reversed String: " << reverseString(str) << endl;

    return 0;
}