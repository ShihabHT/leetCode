#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int oneTime=0, twoTime=0;
        for(int n : nums){
            oneTime = (oneTime ^ n) & (~twoTime);
            twoTime = (twoTime ^ n) & (~oneTime);
        }
        return oneTime;
    }
};

int main(){
    vector<int> nums={2,2,3,2};
    Solution sol;
    cout<<sol.singleNumber(nums)<<endl;

    return 0;
}
/*
  137. Single Number II
Medium

Given an integer array nums where every element appears three times except for one, which appears
exactly once. Find the single element and return it.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 

Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.
*/