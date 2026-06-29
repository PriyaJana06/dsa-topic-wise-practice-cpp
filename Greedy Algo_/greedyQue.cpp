#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Que: Max. Length Chain of Pairs: variant of Activity Selection
bool compare(pair<int, int>& p1, pair<int,int>& p2){
    return p1.second < p2.second;   // ascending order
}

int maxChainLength(vector<pair<int, int>>& pairs){
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
int coinsChange(vector<int>& coins, int amount){
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

// Que: Job Sequencing Problem:  TC = O(N)
bool compareJob(pair<int, int> p1, pair<int, int> p2){
    return p1.second > p2.second;   // descending order
}

int jobSequencing(vector<pair<int, int>> pairs){
    sort(pairs.begin(), pairs.end(), compareJob);
    // first - deadline; second -> profit

    int profit = pairs[0].second;
    int safeDeadline = 2;

    for(int i=1; i<pairs.size(); i++){
        if(pairs[i].first >= safeDeadline){  // non-overlapping job
            profit += pairs[i].second;
            safeDeadline++;
        }
    }
    return profit;
}

// Using vectors of Objects:
// Printing Job Sequence: need to preserve idx no.
class Job{
    public:
    int idx;
    int deadline;
    int profit;

    Job(int idx, int deadline, int profit){
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

void jobSequence(vector<pair<int,int>> pairs){
    int n = pairs.size();
    vector<Job> jobs;

    for(int i = 0; i<n; i++){
        jobs.emplace_back(i, pairs[i].first, pairs[i].second);  // vector of objects
    }

    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b){
        return a.profit > b.profit;  // descending order sort on basis of profit
    });  // capture list-> lamda functions-> single use only

    cout << "Selecting Job " << jobs[0].idx << endl;
    int profit = jobs[0].profit;
    int safeDeadline = 2;

    for(int i=1; i<n; i++){
        if(jobs[i].deadline >= safeDeadline){
            cout << "Selecting Job " << jobs[i].idx << endl;
            profit += jobs[i].profit;
            safeDeadline++;
        }
    }   
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


    // Que: Job Sequencing Problem:
    int n1 = 4;
    vector<pair<int,int>> jobs(n1, make_pair(0, 0));
    jobs[0] = make_pair(4, 20);
    jobs[1] = make_pair(1, 10);
    jobs[2] = make_pair(1, 40);
    jobs[3] = make_pair(1, 30);

    cout << "Max. profit from jobs: " << jobSequencing(jobs) << endl;
    cout << "Sequence of Jobs:\n";
    jobSequence(jobs);


    return 0;
}