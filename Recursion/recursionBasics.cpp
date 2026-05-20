#include<iostream>
using namespace std;

// Factorial
int factorial(int n){
    if(n == 0)
        return 1;   // Base Case

    return n * factorial(n-1);  // 5 * 4!
}


int main(){
    
    // Factorial
    int n = 5;
    // cout << "Factorial of " << n << ": " << factorial(n) << endl; 


    return 0;
}