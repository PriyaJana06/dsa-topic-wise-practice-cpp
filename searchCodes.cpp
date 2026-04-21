#include<iostream>
using namespace std;

// LINEAR SEARCH:
int linearSearch(int *arr, int n, int key){
    for(int i=0; i<n; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

// Binary Search:
int binarySearch(int *arr, int n, int key){
    int start = 0, end = n-1;
    while(start<=end){
        int mid = (start + end)/2;
        if(arr[mid] < key){   // 2nd half
            start = mid+1;   
        } else if(arr[mid]> key){  // 1st half
            end = mid-1;
        } else { 
            return mid;   // Key found
        }
    }
    return -1;
}

int main(){
    // LINEAR SEARCH: TC -> O(N)
    int arr[] = {2, 4, 5, 67, 10, 35, 14, 16, 13};
    int n = sizeof(arr)/sizeof(int);
    cout << linearSearch(arr, n, 13) << endl;

    // BINARY SEARCH: TC -> O(log N)
    cout << "Key Found at index " << binarySearch(arr, n, 34) << endl;

    return 0;
}