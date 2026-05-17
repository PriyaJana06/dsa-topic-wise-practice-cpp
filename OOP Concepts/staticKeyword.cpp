#include<iostream>
using namespace std;

//static in class


void counter(){
    static int count = 0;  // static in function
    count++;
    cout << "Count: " << count << endl;
}

int main(){
    counter();
    counter();
    counter();
    
    return 0;
}