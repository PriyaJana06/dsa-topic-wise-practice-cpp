#include<iostream>
using namespace std;

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

// Clear ith Bit
int clearIthBit(int num, int i){
    int bitMask = ~(1 << i);
    return num & bitMask;
}

// Que: Update ith Bit according to value(0 or 1)
int updateIthBit(int num, int i, int val){
    num = num & ~(1 << i);   // clear ith Bit
    num = num | (val << i);
    return num;
}

// Que: Clear last i Bits of a number
int clearLastIBits(int num, int i){
    int bitMask = (~0) << i;
    return num & bitMask;
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


    // Get ith Bit 
    // int num = 7 ;
    // cout << getIthBit(num, 2) << endl;
    
    // Set ith Bit
    // cout << setIthBit(6, 3) << endl;  // Decimal No: 14
    // cout << setIthBit(7, 3) << endl;  
     
    // Clear ith Bit
    // cout << clearIthBit(6, 1) << endl;


    //Que: Update ith bit according to given value(0 or 1)
    // cout << updateIthBit(7, 3, 1) << endl;

    // Que: Clear last i bits of a number
    // cout << clearLastIBits(15, 2) << endl;
    // cout << clearLastIBits(16, 4) << endl; 


    return 0;
}