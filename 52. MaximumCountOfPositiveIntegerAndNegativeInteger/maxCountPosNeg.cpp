#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos=0, neg =0, len = nums.size();
        for(int i=0; i<len; i++){
            if(nums[i]>0) pos++;
            if(nums[i]<0) neg++;
        }
        return (pos>neg) ? pos : neg;
    }
};

int main(){
    vector<int> nums = {-3,-2,-1,0,0,1,2,4,5};
    Solution sol;
    cout << sol.maximumCount(nums);

    return 0;
}
/*
  2529. Maximum Count of Positive Integer and Negative Integer

Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.

In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
Note that 0 is neither positive nor negative.

Example 1:

Input: nums = [-2,-1,-1,1,2,3]
Output: 3
Explanation: There are 3 positive integers and 3 negative integers. The maximum count among them is 3.
*/