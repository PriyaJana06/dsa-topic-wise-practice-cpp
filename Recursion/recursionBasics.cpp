#include<iostream>
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
    if(i == n-1) return true;  // BaseCase

    if(arr[i] > arr[i+1]) return false;  // Work

    return isSorted(arr, n, i+1);       // Faith
}



int main(){
    
    int n = 6;
    // Factorial
    // cout << "Factorial of " << n << ": " << factorial(n) << endl; 

    // Print n to 1
    // print(n);

    // Sum of N natural numbers
    // cout << sum(n);

    // Print Nth Fiboncci Number
    // cout << fibo(n);

    // Check if Array is Sorted:
    int arr2[] = {1, 3, 5, 2, 5, 8, 2};  // unsorted -> 0
    int arr[] = {1, 2, 3, 4, 5, 6, 7}; // unsorted -> 0
    cout << isSorted(arr2, 7, 0);

    return 0;
}