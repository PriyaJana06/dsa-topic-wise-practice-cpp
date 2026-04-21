#include<iostream>
#include<vector>
using namespace std;

// Linear Search in 2D Array
void linearSearch2D(int mat[][3], int rows, int cols, int key){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(mat[i][j] == key){
                cout << i << " " << j;
            }
        }
    }
    cout << "Not Found" << endl;
}

// Spiral Matrix
vector<int> spiralOrder(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        int srow = 0, scol = 0, erow = rows-1, ecol = cols-1;
        vector<int> result;

        while(srow <= erow && scol <= ecol){  //condition for odd matrix (n != m) 
            //top
            for(int j = scol; j <= ecol; j++){
                result.push_back(mat[srow][j]);
            }

            //right
            for(int j = srow+1; j <= erow; j++){
                result.push_back(mat[j][ecol]);
            }

            //bottom
            for(int j = ecol-1; j >= scol; j--){
                if(srow == erow){    // middle row
                    break;
                }
                result.push_back(mat[erow][j]);
            }

            //left
            for(int i = erow-1; i >= srow+1; i--){
                if(scol == ecol){   // middle column
                    break;
                }
                result.push_back(mat[i][scol]);
            }
            srow++; scol++;
            erow--; ecol--;
        }
        return result;
    }

int main(){

    // Linear search in 2D Array
    int key; cout << "Enter key: "; cin>>key;
    int rows = 3; int cols = 3;
    int mat[3][3] = {{1, 2, 4},
                    {3, 5, 8},
                    {7, 9, 10}};
    linearSearch2D(mat, rows, cols, key);

    int result;
    if(result == 1){
        cout << "Element FOUND"<< "\n";
    } else {
        cout << "Element NOT FOUND" << "\n";
    }


    // Spiral Matrix:
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<int> ans = spiralOrder(matrix);
    cout << "Spiral Order: ";
    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}