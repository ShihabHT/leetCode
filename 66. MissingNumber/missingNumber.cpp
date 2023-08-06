#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int sumOfNums = 0;
        for(int i=0; i<len; i++){
            sumOfNums += nums[i];
        }
        return ((len*(len+1))/2) - sumOfNums;
    }
};

int main(){
    vector<int> nums={3,0,1};
    Solution sol;
    cout<<sol.missingNumber(nums);

    return 0;
}

/*
  268. Missing Number
Easy

Given an array nums containing n distinct numbers in the range [0, n], return the
only number in the range that is missing from the array.

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3].
2 is the missing number in the range since it does not appear in nums.
*/