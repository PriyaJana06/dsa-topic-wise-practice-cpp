#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Que: Activities Selection:
int maxActivities(vector<int> start, vector<int> end){
    // sort on end-time basis
    // always select A0:
    cout << "Selecting A0\n";
    int count = 1;
    int currEndTime = end[0];

    for(int i=1; i < start.size(); i++){
        if(start[i] >= currEndTime){   // non-overlapping
            cout << "Selecting A" << i << endl;
            count++;
            currEndTime = end[i];
        }
    }
    return count;
}

int main(){

    // Que: Activities Selection:
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout << "No. of max. Activities: " << maxActivities(start, end) << endl;

    
    return 0;
}