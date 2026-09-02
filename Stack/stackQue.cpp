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
void stockSpan(vector<int>& stock, vector<int>& span){
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

// Que: Next Greater Element - TC = O(n)
void nextGreater(vector<int>& arr, vector<int>& ans){
    stack<int> s;
    int n = arr.size();
    ans[n-1] = -1; 
    s.push(arr[n-1]);
    
    for(int idx = n-2; idx>= 0; idx--){
        int curr = arr[idx];
        while(!s.empty() && curr >= s.top()){
            s.pop();
        }

        if(s.empty()){
            ans[idx] = -1;
        } else {
            ans[idx] = s.top();
        }
        s.push(curr);
    }

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    } cout << endl; 
}

// Que: Valid Parenthesis:  TC = O(N) | SC = O(N)
bool isValidParenthesis(string str){
    stack<char> s;

    for(int i=0; i<str.size(); i++){
        char ch = str[i];
        // opening char
        if(ch == '(' || ch == '[' || ch == '{'){
            s.push(ch); 
        } else {  // closing char: corner case
            if(s.empty()){
                return false;
            } 

            // match with top of stack
            int top = s.top();
            if((top == '(' && ch == ')') || 
                (top == '[' && ch == ']') || 
                (top == '{' && ch == '}')){
                    s.pop();
            } else {
                return false;
            }
        }
    }

    return s.empty();
}

// Que: Duplicate Parenthesis: TC = O(N) | SC = O(N)
bool isDuplicateParenthesis(string str){
    stack<char> s;

    for(int i=0; i<str.size(); i++){
        char ch = str[i];

        if(ch != ')'){
            s.push(ch);
        } else {
            if(s.top() == '('){
                return true;   // duplicate
            }
             
            while(s.top() != '('){
                s.pop();
            }
            s.pop();    // to remove opening char from stack if closing is found
        } 
    }
    return false;
}

// Que: Max Area of Histogram:  TC = O(N)
int maxAreaHistogram(vector<int> &height){
    int n = height.size();
    vector<int> nsl(n);   // next smaller left
    vector<int> nsr(n);   // next smaller right
    stack<int> s;

    // next smaller left:
    nsl[0] = -1;
    s.push(0);
    for(int i=1; i<height.size(); i++){
        int curr = height[i];
        while(!s.empty() && curr <= height[s.top()]){
            s.pop();
        }

        if(s.empty()){
            nsl[i] = -1;
        } else {
            nsl[i] = s.top();
        } 
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }

    // next smaller right:
    s.push(n-1);
    nsr[n-1] = n;
    for(int i=n-2; i>=0; i--){
        int curr = height[i];
        while(!s.empty() && curr <= height[s.top()]){
            s.pop();
        }

        if(s.empty()){
            nsr[i] = n;
        } else {
            nsr[i] = s.top();
;       }
        s.push(i);
    } 

    int maxArea = 0;
    for(int i=0; i<n; i++){
        int ht = height[i];
        int width = nsr[i] - nsl[i] -1;
        int area = ht * width;

        maxArea = max(area, maxArea);
    } 
    return maxArea;
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
    
    // Que: Next Greater Element:
    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> ans = {0, 0, 0, 0, 0};
    cout << "Next Greater element: ";
    nextGreater(arr, ans);

    // Que: Valid Parenthesis:
    string str1 = "([}])";   // invalid: insufficient no. of opening brackets
    string str2 = "([{}])";  // valid: true
    cout << "Valid Parenthesis: ";
    cout << isValidParenthesis(str1) << " ";
    cout << isValidParenthesis(str2) << endl;

    // Que: Duplicate Parenthesis:
    string str3 = "((a+b))";
    string str4 = "((a+b)+(c+d))";

    cout << "String has duplicate (): " << isDuplicateParenthesis(str3) << endl;
    cout << "String doesn't have duplicate (): " << isDuplicateParenthesis(str4) << endl;

    // Que: Max. Area of Histogram:
    vector<int> height = {2, 1, 5, 6, 2, 3};
    cout << "Max. Area of Histogram: " << maxAreaHistogram(height) << endl;

    return 0;
}