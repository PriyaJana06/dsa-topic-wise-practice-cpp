#include<iostream>
using namespace std;


int trappingRainwater(int *heights, int n){   // TC -> O(N+N+N) => O(3N) => O(N);  SC -> O(N)
    int leftMax[20000];
    leftMax[0] = heights[0];
    for(int i=1; i<n; i++){
        leftMax[i] = max(leftMax[i-1], heights[i-1]);
        // cout << leftMax[i] << " ";
    }

    int rightMax[20000];
    rightMax[n-1] = heights[n-1];
    for(int i=n-2; i>=0; i--){
        rightMax[i] = max(rightMax[i+1], heights[i+1]);
        // cout << rightMax[i] << " ";
    }

    int watertrap = 0;
    for(int i=0; i<n; i++){
        int currWater = min(leftMax[i], rightMax[i]) - heights[i];
        if(currWater>0){
            watertrap += currWater;
        }
    }
    return watertrap;
}

int containerWithMostWater(int *heights, int n){   // TC -> O(N^2) 
    int maxWater = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int width = j-i;
            int minHeight = min(heights[i], heights[j]);
            int area = width*minHeight;
            maxWater = max(maxWater, area);
        }
    }
    return maxWater;
}

int main(){


    // Trapping Rainwater
    int heights[] = {4, 2, 0, 6, 3, 2, 5};
    int n = sizeof(heights)/sizeof(int);
    cout << "Total Water Trapped: " << trappingRainwater(heights, n);

    // Container with Most Water:
    cout << "Container with Most Water: " << containerWithMostWater(heights, n);
    return 0;
}