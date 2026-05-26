#include<iostream>
#include<string>
using namespace std;

// Tiling Problem - count total ways to tile a floor (2*n) with tiles (2*1)
int tilingProblem(int n){    // logic similar to fibonacci series
    if(n == 0 || n == 1) return 1;

    // Vertical
    int ans1 = tilingProblem(n-1);  // 2xn-1

    // Horizontal
    int ans2 = tilingProblem(n-2);  // 2xn-2

    return ans1 + ans2;
}

int main(){
    // Tiling Problem 
    int n = 5;
    cout << "No. of ways tiles(2 x 1) can be placed on floor(2 x "<< n << "): " << tilingProblem(n) << endl;

    return 0;
}