#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int n : nums){
            cout<<map.count(n)<<endl;
            /*we will delete the key that has the value of 2. cause value has been increases
            and made 2 in the previous operation, and this time it will be three but instead
            of making it 3 we will erase, and finally the map will have only one key which
            has the value of 1.*/
            if(map[n]==2) map.erase(n);
            else map[n] += 1;
        }
        return map.begin()->first;
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