#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> numOfCoin(amount+1, INT_MAX);
        numOfCoin[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(int coin : coins){
                if(coin <= i && numOfCoin[i-coin]!= INT_MAX)
                numOfCoin[i] = min(numOfCoin[i], numOfCoin[i-coin] + 1);
            }
        }
        return numOfCoin[amount] == INT_MAX ? -1 : numOfCoin[amount];
    }
};

int main(){
    vector<int> coins = {1,2,5};
    Solution sol;
    cout << sol.coinChange(coins, 12) << endl;

    return 0;
}
/*
  You are given an integer array coins representing coins of different denominations
  and an integer amount representing a total amount of money.
  Return the fewest number of coins that you need to make up that amount. If that
  amount of money cannot be made up by any combination of the coins, return -1.

  You may assume that you have an infinite number of each kind of coin.

  This problem utilizes coin change algorithm
*/