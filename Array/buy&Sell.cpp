#include<iostream>
#include<climits>
using namespace std;

void buyNSellStocks1(int *prices, int n){    // TC -> O(n+n) = O(n)
    int bestBuy[100000];   // SC -> O(n) uses extra space to store bestBuy values
    bestBuy[0] = INT_MAX;   // OR bestBuy[0] = arr[0]
    for(int i=1; i<n; i++){
        bestBuy[i] = min(bestBuy[i-1], prices[i-1]);
        // cout << bestBuy[i] << " ";
    }

    int maxProfit = 0;
    for(int i=0; i<n; i++){
        maxProfit = max(maxProfit , prices[i]-bestBuy[i]);
    }
    cout << "Max Profit : " << maxProfit << endl;
}

void buyNSellStocks2(int *prices, int n){    // TC -> O(N) SC -> O(1)
    int bestBuy = prices[0];  // Kadane's Algorithm
    int maxProfit = 0;

    for(int i=1; i<n; i++){ 
        if(prices[i]>bestBuy){   // Selling Price > Buying Price = Profit
            maxProfit = max(maxProfit, prices[i]-bestBuy);
        }
        bestBuy = min(bestBuy, prices[i]);
    }
    cout << "Maximum Profit : " << maxProfit << endl;
}

int main(){

    // Buy & Sell Stocks
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n1 = sizeof(prices)/ sizeof(int);
    buyNSellStocks1(prices , n1);
    buyNSellStocks2(prices, n1);
    
    return 0;
}