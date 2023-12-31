#include <iostream>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;
        int prev_3 = 0;
        int prev_2 = 1;
        int prev_1 = 1;
        int current;
        for(int i = 3; i<=n; i++) {
            current = prev_3 + prev_2 + prev_1;
            prev_3 = prev_2;
            prev_2 = prev_1;
            prev_1 = current;
        }
        return current;
    }
};

int main(){
    Solution sol;
    cout << sol.tribonacci(4) << endl;

    return 0;
}
/*
  1137. N-th Tribonacci Number

The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.
*/