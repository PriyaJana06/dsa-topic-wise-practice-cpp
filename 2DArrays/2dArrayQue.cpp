#include<iostream>
using namespace std;

// Diagonal Sum
int diagonalSum(int mat[][3], int n){  // TC -> O(N^2)
    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j){   // common element exists when both conditions satisfies
                sum += mat[i][j];
            } else if(j == n-i-1){
                sum += mat[i][j];
            }
        }
    }
    return sum;
}


// Search in 2D Sorted Array - II
bool search2DSortedArray(int mat[][4], int n, int m, int key){
    // TC -> O(n+m)
    int r = 0, c = m-1;
    while(c >= 0 && r < n){
        if(mat[r][c] > key){
            c--;    // left 
        } else if (mat[r][c] < key){
            r++;    // down 
        } else {
            cout << "Found at cell (" << r << "," << c << ")\n";
            return true;   // key found
        }
    }
    return false;    // key not found
}

// Matrix Pointer 
void func(int (*mat)[4], int n, int m){
    cout << "0th row ptr " << mat << endl;
    cout << "1st row ptr " << mat+1 << endl;
    cout << "2nd row ptr " << mat+2 << endl;

    cout << "0th row value " << *(mat) << endl;     // internally it stores value but here it shows address only
    cout << "1st row value " << *(mat+1) << endl;
    cout << "2nd row value " << *(mat+2) << endl;
}

int main(){

    // Diagonal Sum 
    int mat[3][3] = {{1, 2, 4},
                    {3, 5, 8},
                    {7, 9, 10}};
    cout << "Diagonal Sum: " << diagonalSum(mat, 3);


    // Search in Rotated Sorted Array II 
    int matrix[4][4] = {{10, 20, 30, 40},
                        {15, 25, 35, 45},
                        {27, 29, 37, 48},
                        {32, 33, 39, 50}};
    cout << search2DSortedArray(matrix, 4, 4, 50);


    // Matrix Pointer:
    cout << matrix << " = " << &matrix[0][0] <<  endl;
    cout << matrix+1 << " != " << &matrix[0][1] <<  endl;
    cout << matrix+1 << " = " << &matrix[1][0] <<  endl;
    cout << matrix+1 << endl;

    func(matrix, 4, 4); 

    // To access element of 2D array using pointers:
    int i = 2, j = 2;
    cout << matrix[i][j] << " = " << *(*(matrix + i) + j) << endl;

    return 0;
}