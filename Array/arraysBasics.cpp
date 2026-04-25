#include<iostream>
using namespace std;

// Array as Pass By Reference:
void func(int arr[]){
    arr[0] = 1000;
}

void func2(int *ptr){
    ptr[1] = 2000;
}

void printArr(int nums[], int n){
    // cout << sizeof(nums) << endl;  // 4 = size of int pointer
    // int n = sizeof(nums)/sizeof(int);  // gives error without passing n as arguments

    for(int i=0; i<n; i++){
        cout << nums[i] << " ";
    } cout << endl;
}


// Reverse An Array: using extra space
void reverseArray(int *arr, int n){
    int copyArr[n];
    for(int i=0; i<n; i++){
        int j = n-i-1;
        copyArr[i] = arr[j];
    }

    for(int i=0; i<n; i++){
        arr[i] = copyArr[i];
    }
}

void reverseArray2(int *arr, int n){
    int start = 0, end = n-1;
    while(start<end){
        //swap OR swap(arr[start], arr[end])
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp; 
        // update
        start++;
        end--;
    }
}



void printArrPointer(int *ptr, int n){
    for(int i=0; i<n; i++){
        cout << *(ptr+i) << " ";
    }
}

int main(){
    // int marks[50];   // stores garbage value
    // int marks[50] = {1, 2, 3};
    // int marks2[] = {23, 34, 46};  // without declaring size of array, compiler automatically creates array of size n;
    // cout << marks[0] << endl;
    // cout << marks[1] << endl;
    // cout << marks[2] << endl;
    // cout << marks2[2] << endl;
    // cout << marks2[3] << endl;
    // cout << marks[4] << endl;
    // cout << marks[50] << endl;  // out of array index(garbage value) 

    // int arr[5] = {1, 2, 3, 5, 6};
    // cout << sizeof(arr) << endl; 
    // cout << sizeof(arr)/sizeof(int) << endl;

/*
    // Output & Input Array:
    // n = sizeof(arr)/sizeof(int);
    // int arr[5] = {7, 5, 2, 1, 3};
    int n; cout << "Enter length of Array: "; cin>>n;
    int arr[n];
    
    // Input:
    cout << "Enter array elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // Output:
    cout << "Array elements are: ";
    for(int i=0; i<=n-1; i++){    // i<n
        cout << arr[i] << " ";   // 7 5 2 1 3 0 0 0 0 0
    }
*/


/*
    // Largest in Array:
    // Smallest in Array:
    int arr[] = {5, 4, 3, 9, 2};
    int n = sizeof(arr)/sizeof(int);

    int max = arr[0];
    int min = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }
    cout << "Largest Number in Array: " << max << endl;
    cout << "Smallest Number in Array: " << min << endl;
*/


    // Array are passed by reference:
    // int a = 5;
    // int *ptr = &a;
    // int arr[] = {23, 45, 46, 67, 86};
    // int n = sizeof(arr)/sizeof(int);
    // cout << ptr << endl;

    // cout << arr << endl;    // gives address of array.
    // cout << *arr << endl;   // gives value of 1st element in array -> arr[0]
    // cout << arr + 1 << endl;   // moves 1 element forward
    // cout << *(arr+1) << endl;   // arr[1]
    // cout << arr+2 << endl;
    
    // func(arr);   // passing array name is eq. to passing pointer.
    // func2(arr);
    // cout << arr[0] << " " << arr[1] << endl;

    // printArr(arr);// error;
    // printArr(arr, n);  // passing n is essential 



    // Reverse an Array:-> using extra space
    // int arr[] = {34, 45, 57, 78, 89, 34, 24, 46, 68};
    // int n = sizeof(arr)/sizeof(int);
    /*
    reverseArray(arr, n);   //SC -> O(n)
    printArr(arr, n);
    // Reverse Array : -> without using extra space(2 Pointer Approach)
    reverseArray2(arr, n);  // SC -> O(1)
    printArr(arr, n);
    */

/*
    // Array Pointer:
    int x = 10;
    int *ptr = &x;
    int y = 25;
    ptr = &y;    // address can be modified
    cout << *ptr << "\n";

    int arr[6]; 
    cout << arr << "\n";
    int z = 24;
    // arr = &z;  // error -> array is constant pointer
*/


    // Pointer Arithmetic:
    // INC & DEC operators
    // int a = 10;
    // int *aptr = &a;
    // cout << aptr << "\n";
    // aptr++;
    // cout << aptr << "\n";
    // aptr--;
    // cout << aptr << "\n";


    // Addition & Subtraction of Constants
    // cout << aptr+2 << "\n";
    // cout << aptr+3 << "\n"; 
    // int arr[] = {1, 3, 4, 6, 6};
    // cout << arr+5 << endl;
    // int n = sizeof(arr)/ sizeof(int);
    // printArrPointer(arr, n);  // print array elements using pointer arithmetic


    // Addition & Subtraction of Pointers
    // int b = 23;
    // int *bptr = &b;
    // int *ptr = aptr+3;
    // cout << ptr << "\n";   // 04
    // cout << bptr << "\n";  //f4
    // cout << ptr - bptr << "\n";   //4 elements
    // cout << aptr << "\n";   // f8
    // cout << bptr << "\n";   //f4
    // cout << aptr-bptr << endl;  // 1 element // gives how many elements apart the two pointers

    // // cout << aptr + bptr << endl;   // INVALID OPERATION
    
    // int arr[] = {1, 3, 4, 6, 6};
    // int *ptr1 = &arr[4];
    // int *ptr2 = &arr[1];
    // cout << ptr1 - ptr2;   // 4 - 1 = 3 elements

    // int arr1[] = {5,10,15,20};
    // int *p = arr1;
    // int *q = arr1 + 2;
    // cout << q - p << "\n";


    // Comparison (== < <= > >=)
    // cout << (p < q) << "\n";
    // cout << (p > q) << "\n";
    // cout << (arr1==p) << "\n";
    



    return 0;
}