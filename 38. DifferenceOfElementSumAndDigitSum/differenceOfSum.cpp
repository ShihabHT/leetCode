#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elementSum = 0;
        int numLen = nums.size();
        for(int i = 0; i<numLen; i++) {
            elementSum += nums[i];
        }
        
        int digitSum = 0;
        for(int j = 0; j < numLen; j++) {
            string strOfNum =to_string(nums[j]);
            int len = strOfNum.size();
            for(int i=0; i < len; i++){
                digitSum += strOfNum[i]-'0';
                cout<<strOfNum[i]-'0'<<endl;
            }
        }
        return abs(elementSum-digitSum);
    }
};

int main(){
    vector<int> nums = {1,15,6,3};
    Solution sol;
    cout << sol.differenceOfSum(nums)<<endl;

    return 0;
}
/*
  2535. Difference Between Element Sum and Digit Sum of an Array

You are given a positive integer array nums.

-The element sum is the sum of all the elements in nums.
-The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.
Return the absolute difference between the element sum and digit sum of nums.

Note that the absolute difference between two integers x and y is defined as |x - y|.
*/