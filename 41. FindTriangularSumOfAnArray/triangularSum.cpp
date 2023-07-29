#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int len = nums.size();
        while(len>1){
            vector<int> newNums(len-1);
            for(int i=0; i < len-1; i++){
                newNums[i] = (nums[i]+nums[i+1])%10;
                cout<<newNums[i]<<endl;
            }
            nums = newNums;
            len = nums.size();
        }
        return nums[0];
    }
};

int main(){
    vector<int> nums = {5};
    Solution sol;
    cout << sol.triangularSum(nums)<<endl;

    return 0;
}
/*
  2221. Find Triangular Sum of an Array

You are given a 0-indexed integer array nums, where nums[i] is a digit between 0 and 9 (inclusive).
The triangular sum of nums is the value of the only element present in nums after the following
process terminates:

1. Let nums comprise of n elements. If n == 1, end the process. Otherwise, create a new 0-indexed
   integer array newNums of length n - 1.
2. For each index i, where 0 <= i < n - 1, assign the value of newNums[i] as (nums[i] + nums[i+1]) % 10,
   where % denotes modulo operator.
3. Replace the array nums with newNums.
4. Repeat the entire process starting from step 1.
Return the triangular sum of nums.
*/