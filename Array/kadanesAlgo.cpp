#include<iostream>
#include<climits>
using namespace std;

void printSubarrays(int *arr, int n){     // TC -> O(n^3)
    for(int start=0; start<n; start++){
        for(int end=start; end<n; end++){
            // cout << "(" << start << "," << end << ")  ";
            for(int i=start; i<=end; i++){
                cout << arr[i];  // prints all subarrays from start to end idx
            }  cout << "  ";
        } cout << endl;
    } 
}

void maxSubarraySum1(int *arr, int n){  // TC -> O(n^3)
    int maxSum = INT_MIN;
    for(int start=0; start<n; start++){
        for(int end=start; end<n; end++){
            int currSum = 0;
            for(int i=start; i<=end; i++){
                currSum += arr[i];
                maxSum = max(maxSum, currSum);
            }
            cout << currSum << " ";
        } 
        cout << endl;
    }
    cout << "Maximum Subarray Sum: " << maxSum << endl;
}

void maxSubarraySum2(int *arr, int n){    // TC -> O(n^2)
    int maxSum = INT_MIN;
    for(int start=0; start<n; start++){
        int currSum = 0;
        for(int end=start; end<n; end++){
            currSum += arr[end];
            maxSum = max(currSum, maxSum);
        }
    }
    cout << "Maximum Subarray Sum: " << maxSum << endl;
}

void kadanesAlgo(int *arr, int n){   // TC -> O(n) 
    int currSum = 0;
    int maxSum = arr[0];
    for(int i=0; i<n; i++){
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        if(currSum < 0){
            currSum = 0;
        } 
    } cout << "Maximum Subarray Sum: " << maxSum << endl;
}

int main(){
    // Maximum Subarray Sum
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr)/sizeof(int);
    
    printSubarrays(arr, n); cout << "\n";
    maxSubarraySum1(arr, n);
    maxSubarraySum2(arr, n);
    kadanesAlgo(arr, n);

    return 0;
}