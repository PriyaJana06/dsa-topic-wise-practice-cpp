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


// Que: Grid Ways:
int gridWays(int row, int col, int n, int m, string ans){
    if(row == n-1 && col == m-1){   // reached destination
        cout << ans << "\n"; 
        return 1;
    }

    if(row >= n || col >= m){  // Base Case for rows & cols
        return 0;
    }

    // right
    int way1 = gridWays(row, col+1, n, m, ans+'R');
    // down
    int way2 = gridWays(row+1, col, n, m, ans+'D');

    return way1+way2;
}

// Que: Sudoku Solver:
void printSudoku(int sudoku[][9]){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafeSudo(int sudoku[][9], int row, int col, int digit){
    // vertical - col fixed, row = 0 to 8
    for(int i=0; i<9; i++){
        if(sudoku[i][col] == digit){
            return false;
        }
    }

    // horizontal - row fixed, col = 0 to 8
    for(int j=0; j<9; j++){
        if(sudoku[row][j] == digit){
            return false;
        }
    }

    // 3x3 subgrid - 
    int startRow = (row/3)*3;
    int startCol = (col/3)*3;

    for(int i=startRow; i<=startRow + 2; i++){
        for(int j=startCol; j<=startCol+2; j++){
            if(sudoku[i][j] == digit){
                return false;
            }
        }
    }

    return true;
}

bool sudokuSolver(int sudoku[9][9], int row, int col){
    // Base Case
    if(row == 9){
        // sudoku solved
        printSudoku(sudoku);
        return true;
    }

    int nextRow = row;
    int nextCol = col + 1;

    if(col + 1 == 9){
        nextRow = row + 1;
        nextCol = 0;
    }

    // exists a number in cell
    if(sudoku[row][col] != 0){   
        return sudokuSolver(sudoku, nextRow, nextCol);  // move to next cell
    }

    // there exists NO number in cell
    for(int digit=1; digit<=9; digit++){
        if(isSafeSudo(sudoku, row, col, digit)){
            sudoku[row][col] = digit;
            if(sudokuSolver(sudoku, nextRow, nextCol)){
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
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
    // vector<vector<char>> board;
    // int n = 4;

    // for(int i=0; i<n; i++){
    //     vector<char> newRow;
    //     for(int j=0; j<n; j++){
    //         newRow.push_back('.');
    //     }
    //     board.push_back(newRow);
    // }

    // int count = nQueens(board, 0);
    // cout << "count: " << count << endl;


    // Grid Ways:
    // int n = 3;
    // int m = 3;
    // string ans = "";
    // cout << "No. of Ways to reach Destination: " << gridWays(0, 0, n, m, ans) << " ways"<< endl;

    // Sudoku Solver:
    int sudoku[9][9] = {{0, 0, 8, 0, 0, 0, 0, 0, 0},
                        {4, 9, 0, 1, 5, 7, 0, 0, 2},
                        {0, 0, 3, 0, 0, 4, 1, 9, 0},
                        {1, 8, 5, 0, 6, 0, 0, 2, 0},
                        {0, 0, 0, 0, 2, 0, 0, 6, 0},
                        {9, 6, 0, 4, 0, 5, 3, 0, 0},
                        {0, 3, 0, 0, 7, 2, 0, 0, 4},
                        {0, 4, 9, 0, 3, 0, 0, 5, 7},
                        {8, 2, 7, 0, 0, 9, 0, 1, 3}};

    sudokuSolver(sudoku, 0, 0);

    return 0;
}