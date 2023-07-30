#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
// this solution exceeds memory limit
class Solution {
public:
    int lastRemaining(int n) {
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        int firstOrLast = 0;
        
        while(n > 1){
            int newNumLen = n/2;
            vector<int> newNums(newNumLen);
            for(int i = 0; i < newNumLen; i++){
                if(firstOrLast & 1) {
                    newNums[newNumLen-i-1] = nums[n - 2 * i - 2];
                }
                else {
                    newNums[i] = nums[2 * i + 1];
                }
            }
            // for(int x : newNums){
            //     cout<<"keep : "<<x<<endl;
            // }
            // cout<<endl;
            nums = newNums;
            n = nums.size();
            firstOrLast++;
        }
        return nums[0];
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