#include <iostream>
using namespace std;

//This problem is basically a fibonacci number problem

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return n;
        if(n == 2) return n;
        int prev_2 = 1;
        int prev_1 = 2;
        int current;
        for(int i = 3; i<=n; i++) {
            current = prev_2 + prev_1;
            prev_2 = prev_1;
            prev_1 = current;
        }
        return current;
    }
};

int main(){
    Solution sol;
    cout << sol.climbStairs(5) << endl;

    return 0;
}
/*
  70. Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/