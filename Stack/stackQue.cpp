#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

void printStack(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }cout << endl;
}

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

//Que: Reverse a stack:  TC = O(n)
void reverseStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s, temp);
}

// Que: Stock Span Problem: 
vector<int> stockSpan(vector<int>& stock, vector<int>& span){
    stack<int> s;

    s.push(0);
    span[0] = 1;   // idx[0]

    int n = stock.size();
    for(int i=1; i<n; i++){   // idx[1]
        int currPrice = stock[i];
        while(!s.empty() && currPrice >= stock[s.top()]){
            s.pop();
        }

        if(s.empty()){
            span[i] = i+1;
        } else {
            int prevHigh = s.top();
            span[i] = i-prevHigh;
        }
        s.push(i);   // push elements into stack 
    }
    
    for(int i=0; i<n; i++){
        cout << span[i] << " ";
    } cout << endl; 
}


int main(){
    // Push At Bottom of Stack:
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);
    // pushAtBottom(s, 4);

    cout << "Stack Elements: ";
    printStack(s);

    //Que: Reverse a string using stack:
    string str = "priyanka";
    cout << "Reversed String: " << reverseString(str) << endl;

    //Que: Reverse Stack:
    reverseStack(s);
    cout << "Reversed Stack: ";
    printStack(s);

    // Que: Stock Span Problem:
    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span = {0, 0, 0, 0, 0, 0, 0};
    cout << "Stock Span: ";
    stockSpan(stock, span);
    

    return 0;
}