#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

// Memory Leak
int* func1(){
    int *ptr = new int;
    *ptr = 1200;
    cout << "Ptr is " << ptr << endl;
    cout << "Ptr points to " << *ptr << endl;

    return ptr;
}


// dynamic memory allocation
void funcInt(){
    int *ptr = new int;
    *ptr = 24;
    cout << *ptr << endl;
 
    delete ptr;    // to delete datatype
}

void funcArr(){
    int size;
    cout << "Enter size of n: ";
    cin >> size;

    int *arr = new int[size];   // allocation of dynamic array in memory

    int x = 1;
    for(int i=0; i<size; i++){
        arr[i] = x;
        cout << arr[i] << " ";
        x++;
    } 
    cout << endl;

    delete [] arr;   // To delete dynamic array 
}


// static memory allocation
void func(){
    int arr[100] = {2, 4, 5, 6};
    for(int i=0; i<4; i++){
        cout << arr[i] << " ";
    }
    return;
}




int main(){

    // func();
     
    // int arr[100] = {1, 2, 4, 6};
    // int size;
    // cout << "Enter size of n: ";
    // cin >> size;

    // int *arr = new int[size];   // allocation of dynamic array in memory

    // int x = 1;
    // for(int i=0; i<size; i++){
    //     arr[i] = x;
    //     cout << arr[i] << " ";
    //     x++;
    // } cout << endl;


    // Dynamic Memory Allocation
    // funcArr();
    // funcInt();


    // Memory Leak;
    // int *x = func1();
    // cout << *x << endl;  // 1200


/*
    // 2D Dynamic Arrays
    int rows, cols;
    cout << "Enter rows: ";
    cin>>rows;
    cout << "Enter colunms: ";
    cin>>cols;

    // allocation of 2D dynamic arrays 
    int* *matrix = new int*[rows];
    for(int i=0; i<rows; i++){
        matrix[i] = new int[cols];
    }

    // data store
    int x=1;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            matrix[i][j] = x++;
            cout << matrix[i][j] << " ";
        } cout << endl;
    }

    cout << matrix[2][2] << endl;
    cout << *(*(matrix + 2) + 2)<< endl;
*/

    
    // Vectors
    // vector<int> vec1;
    // cout << vec1.size() << "\n";

    // vector<int> vec2 = {1, 3, 5, 7, 8};
    // cout << vec2.size() << "\n";

    // vector<int> vec3(5, -1);  // vec3(size of vector, initialization)
    // cout << vec3.size() << "\n";
    // for(int i=0; i<vec3.size(); i++){
    //     cout << vec3[i] << " ";     // vec3 = [-1 -1 -1 -1 -1]
    // } cout << endl;


    // Vector implementation in memory
    // vector<int> vec2 = {1, 3, 5, 7, 8};
    // cout << "Size: " << vec2.size() << "\n";
    // cout << "Capacity: " << vec2.capacity() << "\n";

    // vec2.push_back(6);
    // cout << "Size: " << vec2.size() << "\n";
    // cout << "Capacity: " << vec2.capacity() << "\n";

    // vec2.pop_back();
    // cout << "Size: " << vec2.size() << endl;
    // cout << "Capacity: " << vec2.capacity() << "\n";


/*
    // 2D Vector
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    for(int i=0; i<matrix.size(); i++){   // matrix[i] = ith row
        for(int j=0; j<matrix[i].size(); j++){   //matrix[i].size() = jth column
            cout << matrix[i][j] << " ";
        } cout << endl;
    }
    
// Note: In 2D Vectors, no. of columns can be different.
    vector<vector<int>> matrix2 = {{1,2,3}, {4,5}, {6}};
    for(int i=0; i<matrix2.size(); i++){   // matrix[i] = ith row
        for(int j=0; j<matrix2[i].size(); j++){   //matrix[i].size() = jth column
            cout << matrix2[i][j] << " ";
        } cout << endl;
    }
*/


    // Practice Que:
    // vector<int> v;
    // for(int i=0; i<5; i++){
    //     v.push_back(i);
    // }
    // cout << v.size() << endl;
    // cout << v.capacity() << endl;




    
    

    
     


    return 0;
}