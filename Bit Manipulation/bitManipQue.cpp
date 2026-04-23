#include<iostream>
using namespace std;

// Que: check odd or Even
void oddOrEven(int num){
    if((num & 1))
        cout << "Odd number\n";
    else
        cout << "Even number\n";
}

// Que: Power of 2
bool isPowerof2(int num){
    if(num & (num - 1))
        return false;
    else 
        return true;
}

// Que: Count Set Bits
int countSetBits(int num){
    int count = 0;
    while(num > 0){
        int lastDigit = num & 1;
        count += lastDigit;
        num = num >> 1;
    }
    return count;
}

// Que: Fast Exponentiation
void fastExpo(int x, int n){
    int dupX = x;
    int dupN = n;

    int ans = 1; 
    while(n > 0){
        int lastBit = n & 1;
        if(lastBit){
            ans = ans * x;
        }
        x *= x;
        n = n >> 1;
    }
    cout << "Power of " << dupX << "^" << dupN << ": " << ans << endl; 
    cout << "Value of x: " << x << endl;
}

int main(){

    // Que: Check if no. Odd/Even
    oddOrEven(5);
    oddOrEven(24);
    oddOrEven(-7);
    oddOrEven(-8);


    // Que: Power of 2
    int num = 32;
    if(isPowerof2(num)){
        cout << num << " is Power of 2\n";
    } else {
        cout << num << " is NOT Power of 2\n";
    }

    // Que: Count Set Bits
    cout << countSetBits(11) << endl;


    // Que: Fast Exponentiation
    fastExpo(3, 4);

    return 0;
}