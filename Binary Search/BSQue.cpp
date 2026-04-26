#include<iostream>
#include<vector>
using namespace std;

// Que: Search in Rotated Sorted Array
int searchInRotated(vector<int>& nums, int target){
    int start = 0, end = nums.size()-1;

    while(start <= end){
        int mid = start + (end - start)/2;
        if(nums[mid] == target) return mid;

        if(nums[start] <= nums[mid]){
            if(nums[start] <= target && target <= nums[mid]) 
                end = mid - 1;
            else 
                start = mid + 1;
        } else {
            if(nums[mid] <= target && target <= nums[end])
                start = mid + 1;
            else 
                end = mid - 1;
        }
    }
    return -1;
}

int main(){
    // Search in Rotated Sorted Array
    vector<int> nums = {3, 4, 5, 6, 7, 0, 1, 2};
    cout << "Target found at index: " << searchInRotated(nums, 0) << endl;

    return 0;
}