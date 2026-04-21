#include<iostream>
using namespace std;

// check odd or Even
void oddOrEven(int num){
    if((num & 1))
        cout << "Odd number\n";
    else
        cout << "Even number\n";
}

// get ith bit
int getIthBit(int num, int i){
    int bitMask = 1 << i;

    if(num & bitMask)
        return 1;
    else 
        return 0;
}

// set ith bit
int setIthBit(int num, int i){
    int bitMask = 1 << i;
        return (num | bitMask);
}

int main(){
    //Bitwise Operators
    // cout << (3&5) << endl;
    // cout << (3|5) << endl;
    // cout << (3&7) << endl;
    // cout << (3|8) << endl;
    // cout << ~6 << endl;

    //Bitwise Shift Operators
    // cout << (7<<2) << endl;  //(28) a<<b => a*2^b
    // cout << (7>>2) << endl;   //(1) a>>b => a/2^b

    // Practice Que:
    // cout << (~4) << endl;
    // cout << (8>>2) << endl;
    // cout << (8>>1) << endl;

    //Que: Check if no. Odd/Even
    // oddOrEven(5);
    // oddOrEven(24);
    // oddOrEven(-7);
    // oddOrEven(-8);


    // Get ith Bit
    // int num = 7 ;
    // cout << getIthBit(num, 2) << endl;
    
    // Set ith Bit
    cout << setIthBit(6, 3) << endl;  // Decimal No: 14
    cout << setIthBit(7, 3) << endl;  
     

    // Clear ith Bit




    return 0;
}