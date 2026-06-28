#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Print pairs:
void printPairs(vector<pair<int, int>> pairVec){
    for(int i=0; i<pairVec.size(); i++){
        cout << "A"<< i << ": " << "(" << pairVec[i].first << ", " << pairVec[i].second << ")" << endl;
    } 
    cout << "--------Sorted pairs---------\n";
}

// Custom Logic to sort pair values:
bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;  // ascending - end
    // return p1.second > p2.second;  // descending - end

    // return p1.first < p2.first;   // ascending - start
    // return p1.first > p2.first;   // descending - start
}

int main(){

    // Pairs in C++:
    vector<int> start1 = {0, 1, 3};
    vector<int> end1 = {9, 2, 4};

    // pair<int, int> p;  // single pair
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