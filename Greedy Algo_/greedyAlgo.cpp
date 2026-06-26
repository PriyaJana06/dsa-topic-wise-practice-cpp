#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Print pairs:
void printPairs(vector<pair<int, int>> pairVec){
    for(int i=0; i<pairVec.size(); i++){
        cout << "A"<< i << ": " << "(" << pairVec[i].first << ", " << pairVec[i].second << ")" << endl;
    } 
    cout << "--------Sorted pairs---------\n";
}

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

// Custom Logic to sort pair values:
bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;  // ascending - end
    // return p1.second > p2.second;  // descending - end

    // return p1.first < p2.first;   // ascending - start
    // return p1.first > p2.first;   // descending - start
}

int main(){

    // Que: Activities Selection:
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout << "No. of max. Activities: " << maxActivities(start, end) << endl;

    vector<int> start1 = {0, 1, 3};
    vector<int> end1 = {9, 2, 4};

    // pair<int, int>;  // single pair
    // vector<int> vec(5, 0);

    // vector stores multiple pair:
    vector<pair<int, int>> activity(3, make_pair(0,0));  // empty pair
    activity[0] = make_pair(0, 9);
    activity[1] = make_pair(1, 2);
    activity[2] = make_pair(2, 4);

    printPairs(activity);

    // Sorting pairs:
    sort(activity.begin(), activity.end(), compare);

    printPairs(activity);
    
    return 0;
}