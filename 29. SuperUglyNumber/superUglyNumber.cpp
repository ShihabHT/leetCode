#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> superUglyNum(n, 1);
        vector<int> index(primes.size(), 0);
        int nextUglyNumber;
        int prime2=0, prime3=0, prime5=0;
        for(int i = 1; i < n; i++) {
            long long nextUglyNumber = static_cast<long long>(INT_MAX);
            for(int j = 0; j < primes.size(); j++) {
                nextUglyNumber = min(nextUglyNumber, static_cast<long long>(superUglyNum[index[j]])*primes[j]);
            }
            superUglyNum[i] = nextUglyNumber;
            for(int k = 0; k < primes.size(); k++) {
                if(static_cast<long long>(superUglyNum[index[k]])*primes[k] == nextUglyNumber) index[k]++;
            }
        }
        return superUglyNum[n-1];
    }
};

int main(){
    vector<int> primes = {2,3,5,7};
    Solution sol;
    cout<<sol.nthSuperUglyNumber(5911, primes)<<endl;

    return 0;
}

/*
  An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
  Given an integer n, return the nth ugly number.
*/