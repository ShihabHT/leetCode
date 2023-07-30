#include <iostream>
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        bool leftToRight = true;
        int start = 1, stepSize = 1;
        while(n>1){
            if(leftToRight) start += stepSize;
            else{  //whole else block in one line : start += (n&1)?stepSize:0;
                if(n&1){
                    start += stepSize;
                }
            }
            stepSize *= 2;
            n /= 2;
            leftToRight = !leftToRight;  //basic for alternating
        }
        return start;
    }
};

int main(){
    Solution sol;
    cout<<sol.lastRemaining(1000000000)<<endl;

    return 0;
}
/*
  390. Elimination Game

You have a list arr of all integers in the range [1, n] sorted in a strictly increasing order.
Apply the following algorithm on arr:
1. Starting from left to right, remove the first number and every other number afterward until
   you reach the end of the list.
2. Repeat the previous step again, but this time from right to left, remove the rightmost
   number and every other number from the remaining numbers.
3. Keep repeating the steps again, alternating left to right and right to left, until a single
   number remains.
Given the integer n, return the last number that remains in arr.
*/