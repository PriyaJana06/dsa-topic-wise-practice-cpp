#include<iostream>
#include<vector>
using namespace std;

// Factorial
int factorial(int n){
    if(n == 0)
        return 1;   // Base Case

    return n * factorial(n-1);  // 5 * 4!
}

// Print n to 1
void print(int n){
    if(n == 0) return;  // Base Case 

    cout << n << " ";   // Work
    print(n-1);        // Faith, next call
}

// Segmentation fault-> infinite recursion (stack overflow)
void func(){
    cout << "function is called..Work\n";
    func();
}

// Sum of N natural numbers
int sum(int n){
    if(n == 1) return 1;

    return n + sum(n-1);
}

// Print Nth fibonacci number
int fibo(int n){
    if(n == 0 || n == 1) return n;

    return fibo(n-1) + fibo(n-2);
}

// Check if Array is Sorted:
bool isSorted(int arr[], int n, int i){
    if(i == n-1) return true;  // Base Case

    if(arr[i] > arr[i+1]) return false;  // Work

    return isSorted(arr, n, i+1);       // Faith
}

// First occurence of element in vector:
int firstOccur(vector<int> arr, int target, int i){
    if(i == arr.size()) return -1;   // Base Case

    if(arr[i] == target) return i;   // Work

    return firstOccur(arr, target, i+1);   // Inner Function
}
 
// Last Occurence:
int lastOccur(vector<int> arr, int target, int i){
    if(i == arr.size()) return -1;   // Base Case

    int idx = lastOccur(arr, target, i+1);     // Inner Function
     
    if(idx == -1){               // Work
        if(arr[i] == target) 
            return i;
    }
    return idx;
}

// Print x to the pow n:  // TC -> O(log N)
int pow(int x, int n){
    if(n == 0) return 1;    // Base Case

    int halfPow = pow(x, n/2);   

    if(n % 2 == 0) {       
        return halfPow * halfPow;   // even n
    } else {                            
        return x * halfPow * halfPow;  // odd n
    }
}

int main(){
    
    // int n = 6;
    // Factorial
    // cout << "Factorial of " << n << ": " << factorial(n) << endl; 

    // Print n to 1
    // print(n);

    // Sum of N natural numbers
    // cout << sum(n);

    // Print Nth Fiboncci Number
    // cout << fibo(n);

    // Check if Array is Sorted:
    // int arr2[] = {1, 3, 5, 2, 5, 8, 2};  // unsorted -> 0
    // int arr[] = {1, 2, 3, 4, 5, 6, 7}; // sorted -> 0
    // cout << isSorted(arr2, 7, 0);

    // First Occurence:
    // vector<int> arr = {1, 2, 3, 4, 4, 3, 5};
    // cout << firstOccur(arr, 4, 0) << endl;

    // Last Occurence:
    // vector<int> arr1 = {1, 2, 3, 4, 4, 3, 5};
    // cout << lastOccur(arr1, 4, 0) << endl;
    
    // Print X to the pow N
    int x = 2;
    int n = 10;
    cout << pow(x, n) << endl;

    return 0;
}