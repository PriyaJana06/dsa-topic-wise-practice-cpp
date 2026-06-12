#include<iostream>
#include<vector>
using namespace std;

// Que: N Queens -> Place N-Queens such that NO 2 queens attack each other.
void printBoard(vector<vector<char>>& board){
    int n = board.size();   // size of row

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        } cout << endl;
    }

    cout << "----------------\n";
}

bool isSafeQ(vector<vector<char>>& board, int row, int col ){
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

int nQueens(vector<vector<char>>& board, int row){  // placing ith queen -> ith Row
    int n = board.size();

    if(row == n){
        printBoard(board); 
        return 1;
    }
    
    int count = 0;
    for(int j=0; j<n; j++){  // columns
        if(isSafeQ(board, row, j)){
            board[row][j] = 'Q';
            count += nQueens(board, row+1);
            board[row][j] = '.';  // Backtracking
        }
    }
    return count;   // no. of possible solutions
}


int main(){

    // Que: (IMP) N-Queens:
    vector<vector<char>> board;
    int n; 
    cout << "Enter number of Queens: ";
    cin >> n;

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