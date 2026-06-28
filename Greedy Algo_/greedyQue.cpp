#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Que: Max. Length Chain of Pairs: variant of Activity Selection
bool compare(pair<int, int> p1, pair<int,int> p2){
    return p1.second < p2.second;   // ascending order
}

int maxChainLength(vector<pair<int, int>> pairs){
    int n = pairs.size();

    sort(pairs.begin(), pairs.end(), compare);
    int ans = 1; 
    int currEnd = pairs[0].second;

    for(int i=1; i<n; i++){
        if(pairs[i].first > currEnd){   // non-overlapping
            ans++;
            currEnd = pairs[i].second;
        }
    }
    return ans;
}

// Que: Indian Coins:  find no. of coins to make change for given amount -> TC = O(n) ~ O(1)
int coinsChange(vector<int> coins, int amount){
    int ans = 0;
    int n = coins.size();

    cout << "Denominations used: ";
    for(int i = n-1; i >= 0 && amount > 0; i--){
        if(amount >= coins[i]){
            ans += amount/coins[i];
            amount %= coins[i];
            cout << coins[i] << " ";
        }
    } cout << "\n";
    return ans;
}

int main(){

    // Que: Max. Length Chain of Pairs:
    int n = 5;
    vector<pair<int,int>> pairs(n, make_pair(0, 0));

    pairs[0] = make_pair(5, 24);
    pairs[1] = make_pair(39, 60);
    pairs[2] = make_pair(5, 28);
    pairs[3] = make_pair(27, 40);
    pairs[4] = make_pair(50, 90);

    cout << "Max. Chain length of pairs: " << maxChainLength(pairs) << endl;


    // Que: Indian Coins:
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int amount = 1099;

    cout << "Min. coins for change: " << coinsChange(coins, amount) << endl;

    return 0;
}