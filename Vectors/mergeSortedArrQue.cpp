#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Square of Sorted Array
vector<int> sortedSquares(vector<int>& nums){
    int size = nums.size();
    vector<int> pos;
    vector<int> neg;

    // Segregate negative & positive elements
    for(int i=0; i<size; i++){
        if(nums[i] >= 0)
            pos.push_back(nums[i]);
        else 
            neg.push_back(nums[i]);
    }

    // Only Positive array
    if(neg.size() == 0){
        for(int i=0; i<pos.size(); i++)
            pos[i] = pos[i] * pos[i];
        return pos;
    }

    // Only Negative Array
    if(pos.size() == 0){
        for(int i=0; i<neg.size(); i++){
            neg[i] = neg[i] * neg[i];
        }
        reverse(neg.begin(), neg.end());
        return neg;
    }

    // Merge Sorted Array Part
    int i=0, j=0;
    int idx = 0;
    int m = pos.size();
    int n = neg.size();

    vector<int> res(n+m);
    
    for(int i=0; i<n; i++){
        neg[i] = neg[i] * neg[i];
    }
    reverse(neg.begin(), neg.end());

    for(int i=0; i<m; i++){
        pos[i] = pos[i] * pos[i];
    }

    while(i<n && j<m){
        if(neg[i] <= pos[j]){
            res[idx++] = neg[i++];
        } else {
            res[idx++] = pos[j++];
        }
    }

    while(i<n){
        res[idx++] = neg[i++]; 
    }
    while(j<m){
        res[idx++] = pos[j++];
    }
    return res;
}

int main(){

    // Merge 2 Sorted array - Two Pointers Approach
    // Time Complexity - O(n)
    int n = 3, m = 4;
    int arr1[n] = {1, 2, 3};
    int arr2[m] = {3, 6, 7, 9};

    // i) part
    int i=0, j=0;
    vector<int> result;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            result.push_back(arr1[i]);
            i++;
        } else {
            result.push_back(arr2[j]);
            j++;
        }
    }
    //ii) part - Edge Cases
    while(j<m){
        result.push_back(arr2[j]);
        j++;
    }
    while(i<n){
        result.push_back(arr1[i]);
        i++;
    }

    cout << "Merged 2 Sorted Array: ";
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    } cout << "\n";


// Que:
    // Square of a Sorted Array: Merge two Sorted Array & Two Pointers Approach
    vector<int> nums = {-4, -1, 0, 3, 10};
    
    cout << "Square of Sorted Array: ";
    vector<int> ans = sortedSquares(nums);
    for(int i=0; i<nums.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}