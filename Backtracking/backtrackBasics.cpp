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

// Que: Find Subsets of string:
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

// Que: Find & Print all permutations:
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

// Que: N Queens -> Place N-Queens such that NO 2 queens attack each other.
void printBoard(vector<vector<char>> board){
    int n = board.size();   // size of row

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        } cout << endl;
    }

    cout << "----------------\n";
}

bool isSafe(vector<vector<char>> board, int row, int col ){
    int n = board.size();
    // horizontal safety:
    for(int j=0; j<n; j++){
        if(board[row][j] == 'Q'){
            return false;
        }
    }

    // vertical safety:
    for(int i=0; i<row; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }

    // diagonal left:
    for(int i=row, j=col; i>=0 && j>=0; i--,j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    // diagonal right:
    for(int i=row, j=col; i>=0 && j<n ; i--, j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

int nQueens(vector<vector<char>> board, int row){  // placing ith queen -> ith Row
    int n = board.size();

    if(row == n){
        printBoard(board); 
        return 1;
    }
    
    int count = 0;
    for(int j=0; j<n; j++){  // columns
        if(isSafe(board, row, j)){
            board[row][j] = 'Q';
            count += nQueens(board, row+1);
            board[row][j] = '.';  // Backtracking
        }
    }
    return count;   // no. of possible solutions
}


int main() {
    // int arr[5] = {0};
    // int n = 5;

    // changeArr(arr, n, 0);
    // printArr(arr, n);

    
    // Find Subsets of string:
    // string str = "abc";
    // string subset = "";
    // printSubsets(str, subset);

    // Find Permutations:
    // string str = "abc";
    // string ans = "";

    // findPermutations(str, ans);


    // Que: (IMP) N-Queens:
    vector<vector<char>> board;
    int n = 4;

    for(int i=0; i<n; i++){
        vector<char> newRow;
        for(int j=0; j<n; j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }

    int count = nQueens(board, 0);
    cout << "count: " << count << endl;
    return 0;
}