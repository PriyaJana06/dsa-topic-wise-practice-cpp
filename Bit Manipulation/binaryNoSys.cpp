#include<iostream>
using namespace std;

void binToDec(int binNum){
    int n = binNum;
    int decNum = 0;
    int pow = 1;    //2^0 *= 2^1 2^2...

    while(n > 0){
        int lastDig = n%10;
        decNum += lastDig * pow;
        pow *= 2;
        n/=10;
    } cout << "Decimal Number of " << binNum << " is " << decNum;
}

void decToBin(int decNum){
    int n = decNum;
    int binNum = 0;
    int pow = 1;  // 10^0 *= 10^1 10^2..

    while(n > 0){
        int rem = n%2;
        binNum += rem*pow;
        pow*=10;
        n/=2;
    } cout << "Binary Number of " << decNum << " is " << binNum;
}

int main(){

    int binNum; cout << "Enter binary number: "; cin>>binNum;
    binToDec(binNum); cout << "\n";
    int decNum; cout << "Enter decimal number: "; cin>>decNum;
    decToBin(decNum);

    
    return 0;
}