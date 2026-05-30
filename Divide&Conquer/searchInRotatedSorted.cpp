#include<iostream>
#include<vector>
using namespace std;

int search(int arr[], int si, int ei, int target){   // O(log N)
    if(si > ei) return -1;    // Base Case

    int mid = si + (ei-si)/2;

    if(arr[mid] == target){
        return mid;
    }

    if(arr[si] <= arr[mid]){   // line 1
        if(arr[si] <= target && target < arr[mid]){
            return search(arr, si, mid-1, target);   // left half
        } else {
            return search(arr, mid+1, ei, target);   // right half
        }
    } 
    else {                       // line 2
        if(arr[mid] < target && target <= arr[ei]){   
            return search(arr, mid+1, ei, target);    // right half
        } else {
            return search(arr, si, mid-1, target);    // left half
        }
    }
}

int main() {
    int n = 7;
    int arr[n] = {4, 5, 6, 7, 0, 1, 2};

    cout << "Element found at index: " << search(arr, 0, n-1, 2) << endl;
    return 0;

}
