#include<iostream>
#include<vector>
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

// Binary Search: Iterative
int binarySearch(int* arr,int n, int key){
    int start = 0, end = n-1;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(arr[mid] < key){   // 2nd half
            start = mid+1;   
        } else if(arr[mid] > key){  // 1st half
            end = mid-1;
        } else { 
            return mid;   // Key found
        }
    }
    return -1;
}

// Binary Search: Recursive
int recBinarySearch(vector<int> arr, int target, int start, int end){
    if(start <= end){
        int mid = start + (end - start)/2;
        if(target > arr[mid]){
            return recBinarySearch(arr, target, mid+1, end);
        } else if(target < arr[mid]){
            return recBinarySearch(arr, target, start, end-1);
        } else {
            return mid;
        }
    }
    return -1;
}


int main(){
    // LINEAR SEARCH: TC -> O(N)
    int arr[] = {2, 4, 5, 67, 10, 35, 14, 16, 13};
    int n = sizeof(arr)/sizeof(int);
    // cout << linearSearch(arr, n, 13) << endl;

    // BINARY SEARCH: TC -> O(log N) SC -> O(1)
    // Iterative BS:
    int arr1[] = {2, 4, 5, 10, 13, 14, 16, 35, 67};
    cout << "Key Found at index: " << binarySearch(arr1,n, 13) << endl;

    // Recursive BS:
    // TC -> O(log N) SC -> O(log N)
    vector<int> arr2 = {-1, 0, 3, 5, 9, 12};
    cout << "Key found at index: " << recBinarySearch(arr2, 12, 0, 5) << endl;


    return 0;
}