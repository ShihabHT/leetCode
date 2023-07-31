#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int prev_2 = 0;
        int prev_1 = 1;
        int current;
        for(int i = 2; i<=n; i++) {
            current = prev_2 + prev_1;
            prev_2 = prev_1;
            prev_1 = current;
        }
        return current;
    }
};

int main(){
    Solution sol;
    cout << sol.fib(30) << endl;

    return 0;
}
/*
  509. Fibonacci Number

The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci
sequence, such that each number is the sum of the two preceding ones, starting
from 0 and 1. That is,
*/