#include<iostream>
#include<string>
using namespace std;

// Tiling Problem - count total ways to tile a floor (2*n) with tiles (2*1)
int tilingProblem(int n){    // logic similar to fibonacci series
    if(n == 0 || n == 1) return 1;

    // Vertical tile
    int ans1 = tilingProblem(n-1);  // 2xn-1

    // Horizontal tile
    int ans2 = tilingProblem(n-2);  // 2xn-2

    return ans1 + ans2;
}

// Remove Duplicates in String:
void removeDuplicates(string str, string ans, int i, bool visited[26]){

    if(i == str.size()){
        cout << "Ans: " << ans << endl;
        return;
    }

    int visitedIdx = (int)(str[i] - 'a');

    if(visited[visitedIdx]){
        removeDuplicates(str, ans, i+1, visited);
    } else {
        visited[visitedIdx] = true;
        removeDuplicates(str, ans+str[i], i+1, visited);
    }
}

int main(){
    // Tiling Problem 
    int n = 5;
    cout << "No. of ways tiles(2 x 1) can be placed on floor(2 x "<< n << "): " << tilingProblem(n) << endl;

    // Remove Duplicates in String:
    string str = "appnnacollege";
    string ans = "";
    bool visited[26] = {false};
    removeDuplicates(str, ans, 0, visited);


    return 0;
}