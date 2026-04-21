#include<iostream>
#include<vector>
using namespace std;

// Pair Sum 
vector<int> pairSum(vector<int>& arr, int target){
    int start = 0, end = arr.size()-1;
    vector<int> ans;

    while(start < end){
        int currSum = arr[start] + arr[end];

        if(currSum > target)
            end--;
        else if(currSum < target)
            start++;
        else {
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }
    }
    return {};
}


int main(){

    // Pair Sum -> Find if any pair in sorted vector has target sum
    vector<int> vec = {2, 7, 11, 15};
    int target = 17;
    vector<int> ans = pairSum(vec, target);
    cout << ans[0] << "," << ans[1] << endl;

    return 0;
}