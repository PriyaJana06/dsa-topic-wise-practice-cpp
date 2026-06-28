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

// Custom Logic to sort pair values:
bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;  // ascending - end
    // return p1.second > p2.second;  // descending - end

    // return p1.first < p2.first;   // ascending - start
    // return p1.first > p2.first;   // descending - start
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


// Que: Fractional Knapsack:  TC -> O(NlogN)
bool fKCompare(pair<double,int> p1, pair<double,int> p2){
    return p1.first > p2.first;
}

int fractionalKnapsack(vector<int> val, vector<int> wt, int W){
    int n = val.size();
    vector<pair<double,int>> ratio(n, make_pair(0.0, 0));   // pair(ratio, idx) -> (double, int)

    for(int i=0; i<n; i++){
        double r = val[i]/(double)wt[i];
        ratio[i] = make_pair(r, i);
    }

    sort(ratio.begin(), ratio.end(), fKCompare);   //O(nlogn)

    int ans = 0;
    for(int i=0; i<n; i++){
        int idx = ratio[i].second;   // wt, val
        if(wt[idx] <= W){
            ans += val[idx];
            W -= wt[idx];
        } else {
            ans += ratio[i].first * W;
            W -= wt[idx];
            break;
        }
    }
    return ans;
}

int main(){
    // Que: Activities Selection:
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    cout << "No. of max. Activities: " << maxActivities(start, end) << endl;


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


    // Que: Fractional Knapsack:
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    cout << "Max. Total Value: " << fractionalKnapsack(val, wt, W) << endl;

    
    // Que: Find sum of Min. absolute difference of pairs:
    vector<int> A = {4, 1, 8, 7};
    vector<int> B = {2, 3, 6, 5};

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int absDiff = 0;
    for(int i=0; i<A.size(); i++){
        absDiff += abs(A[i]-B[i]);
    }

    cout << "Min. Absolute Diffence: " << absDiff << endl;
    
    return 0;
}