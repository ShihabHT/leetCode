#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n==0) return 0;
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2; i*i < n; i++) {
            if(isPrime[i]){
                for(int j = i*i; j < n; j+=i){
                    isPrime[j] = false;
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(isPrime[i]) count++;
        }
        return count;
    }
};

int main(){
    Solution sol;
    cout<<sol.countPrimes(24);
    return 0;
}
/*
  Given an integer n, return the number of prime numbers that are strictly less than n.
*/