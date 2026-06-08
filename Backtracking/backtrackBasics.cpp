#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Backtracking in array:
void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    } cout << endl;
}

void changeArr(int arr[], int n, int i){
    if(i == n){
        printArr(arr, n);
        return;
    }

    arr[i] = i+1;
    changeArr(arr, n, i+1);   // recursion 
    arr[i] -= 2;   // Backtrack
}

// Find Subsets of string:
void printSubsets(string str, string subset){
    if(str.size() == 0){
        cout << subset << "\n";
        return;
    }

    char ch = str[0];
    // str.substr(stIdx, length of str)
    printSubsets(str.substr(1, str.size()-1), subset+ch);   // include
    printSubsets(str.substr(1, str.size()-1), subset);    // exclude
}

// Find & Print all permutations:
void findPermutations(string str, string ans){
    if(str.size() == 0){
            cout << ans << "\n";
            return;
        }

    for(int i=0; i<str.size(); i++){
        char ch = str[i];
        // "abcdefgh", i=2 => "ab" + "defgh" => str.substr(0, i) + str.substr(i+1, str.size()-i-1);
        string nextStr = str.substr(0, i) + str.substr(i+1, str.size()-i-1);
        findPermutations(nextStr , ans + ch);     // ith char choice to add in permutation
    }
}

int main() {
    int arr[5] = {0};
    int n = 5;

    // changeArr(arr, n, 0);
    // printArr(arr, n);


    // Find Subsets of string:
    // string str = "abc";
    // string subset = "";
    // printSubsets(str, subset);

    // Find Permutations:
    string str = "abc";
    string ans = "";

    findPermutations(str, ans);
 
    return 0;
}