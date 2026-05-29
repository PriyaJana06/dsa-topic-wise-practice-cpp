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

// Friends Pairing Problem: Find Total ways in which n friends can be paired up.
// Each friend can only be paired once.
int friendsPairing(int n){
    if(n == 1 || n == 2) return n;
    
    return friendsPairing(n-1) + (n-1)*friendsPairing(n-2);
}

// Binary Strings Problem: Print all Binary Strins of size N without any consecutive 1s.
void binaryString(int n) {
    
}

int main(){
    // Tiling Problem 
    int n = 4;
    cout << "No. of ways tiles(2 x 1) can be placed on floor(2 x "<< n << "): " << tilingProblem(n) << endl;

    // Remove Duplicates in String:
    string str = "appnnacollege";
    string ans = "";
    bool visited[26] = {false};
    removeDuplicates(str, ans, 0, visited);

    // Friends Pairing Problem:
    cout << "Number of total ways for pairing " << n << " friends: " << friendsPairing(n) << endl;


    return 0;
}