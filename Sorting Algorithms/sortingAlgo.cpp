#include<iostream>
#include<climits>
using namespace std;

void printArr(int *arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

void inputArr(int *arr, int n){
    cout << "Enter array element: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
}

void bubbleSort(int *arr, int n){   // TC -> O(n^2) 
    for(int i=0; i<n-1; i++){
        bool isSwap = false;   // Optimisation for already sorted array or no swaps
        // cout << "Outerloop" << " ";
        for(int j=0; j<n-i-1; j++){
            // cout << "Innerloop" << " ";
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                isSwap = true;   // atleast one swap happened in each pass 
            }
        }
        if(!isSwap){
            // Array is already sorted
            return;
        }
    }
}

void selectionSort(int *arr, int n){  // TC -> O(n^2)
    for(int i=0; i<n-1; i++){
        int minIdx = i;   // Index of minimum value
        for(int j=i+1; j<n; j++){  // this loop is only for checking idx of minimum element not for swaping elements 
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
    printArr(arr, n);
}

void insertionSort(int *arr, int n){  // TC -> O(n^2)
    for(int i=1; i<n; i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev]>curr){
            swap(arr[prev], arr[prev+1]);
            prev--;
        }
        arr[prev+1] = curr;
    } printArr(arr, n);
}

void countingSort(int *arr, int n){   // TC -> O(N + range)
    int freq[100000] = {0};
    int minVal = INT_MAX, maxVal = INT_MIN;

    //1st Step - O(n)
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    //2nd Step - O(range) = max - min
    for(int i=minVal, j=0; i<=maxVal; i++){
        while (freq[i] > 0){
            arr[j++] = i;
            freq[i]--;
        }
    }
    printArr(arr, n);
}



int main(){
    int n; cout << "Enter number of elements: "; cin>>n;
    int arr[n];
    inputArr(arr, n); 

    bubbleSort(arr, n); 
    cout << "Bubble Sort: "; 
    printArr(arr, n);  cout << "\n";

    cout << "Selection Sort: ";
    selectionSort(arr, n); cout << "\n";

    cout << "Insertion Sort: ";
    insertionSort(arr, n);  cout << "\n";

    cout << "Counting Sort: ";
    countingSort(arr, n); cout << "\n";
    
    return 0;
}