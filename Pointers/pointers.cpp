#include<iostream>
using namespace std;

void changeA(int a){
    a = 100;
    cout << a << "\n";
}

int square(int n){
    n *= n;
    return n;
}

// Pass By Reference (using Pointers):
void changeA2(int *ptr){
    *ptr = 100;
    cout << *ptr << "\n";
}

// Pass By Reference (using Reference Variables):
void changeA3(int &a){
    a = 100;
    cout << a << "\n";
}

// Assignment Que:
void multiplyBy2(int &a, int &b, int &c){
    a *= 2;
    b *= 2;
    c *= 2;
}

int main(){

    // int ptr = &a;   // error
    // int *ptr = 10;  // error
    // int a = 10;
    // float b = 15.2;
    // int *ptr = &a;
    // float *ptr2 = &b;


    // cout << &a << " = " << ptr << "\n";   // prints address of a variable
    // cout << &b << " = " << ptr2 << "\n";


    // cout << sizeof(ptr) << "\n";    // 4 bytes
    // cout << sizeof(ptr2) << "\n";    // 4 bytes


    // pointer to pointer variable
    // int **pptr = &ptr;
    // float **pptr2 = &ptr2;
    // cout << &ptr << " = " << pptr << "\n";
    // cout << &ptr2 << " = " << pptr2 << "\n";


    // Dereference Operator -> Gets the value of the variable pointed by any pointer.
    // * operator lets us directly access & modify the value of variable.
    // cout << &a << "\n";
    // cout << *(&a) << " = " << *ptr << "\n";  

    // *ptr = 20;
    // cout << a << "\n";


    // Null Pointer:
    // int *ptr3;
    // cout << ptr3 << "\n";   // gives garbage memory address.

    // int *ptr3 = NULL;
    // cout << ptr3 << "\n";   // gives 0 memory address.
    // cout << *ptr3 << "\n";     // error -> segmentation faultj(dereferencing null ptr)

   
    // Passing Arguments:
    // Pass By Value: copy of variable is created. 
    // int x = 15;
    // changeA(x);
    // cout << x << "\n";

    // int n = 5;
    // cout << square(n) << endl;
    // cout << n << endl;


    // Pass By Reference: (using Pointers)
    // int x = 10;
    // changeA2(&x);
    // cout << x << "\n";

    // Pass By Reference: (using Reference Variables)
    // int y = 23;
    // int &ref = y;
    // cout << y << endl;
    // cout << ref << endl;
    // cout << &y << endl;
    // cout << &ref << endl;

    // changeA3(y);
    // cout << y << "\n";


/*
    //Que:
    // what will ptr2 point to?
    int x = 5, y = 10;
    int *ptr1 = &x, *ptr2 = &y;
    ptr2 = ptr1;
    cout << &x << "\n";
    cout << ptr1 << " " << ptr2 << "\n";

    // Can a pointer initialized with zero?
    int *ptr = 0;
    cout << ptr << "\n";   // Null ptr -> returns 0
*/



    //Assignment Que's:

    //Que1:
    // int x;
    // int *ptr;
    // x=7;
    // ptr = &x; cout << *ptr;  //7

    //Que2:
    int x = 1, y=2, z=3;
    multiplyBy2(x, y, z);
    cout << x << y << z << "\n";

    //Que3:
    int a = 32;
    int *ptr = &a;
    char ch = 'A';
    char &cho = ch;

    cho += a;
    *ptr += ch; 
    cout << a << ", " << ch << endl;   // 129, a



    return 0;
}