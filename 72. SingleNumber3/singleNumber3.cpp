#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        vector<int> res;
        for(int n : nums){
            cout<<map.count(n)<<endl;
            /*we will delete the key that has the value of 2. cause value has been increases
            and made 2 in the previous operation, and this time it will be three but instead
            of making it 3 we will erase, and finally the map will have only one key which
            has the value of 1.*/
            if(map[n]==1) map.erase(n);
            else map[n] += 1;
        }
        for(auto it=map.begin(); it!=map.end(); it++){
            res.push_back(it->first);
        }
        
        return res;
    }
};

int main(){
    vector<int> nums={1,2,1,3,2,5};
    vector<int> res;
    Solution sol;
    res = sol.singleNumber(nums);
    for(int i : res){
        cout << i << " ";
    }

    return 0;
}
/*
  260. Single Number III
Medium

Given an integer array nums, in which exactly two elements appear only once and all the
other elements appear exactly twice. Find the two elements that appear only once. You can
return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant
extra space.

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]
 

Constraints:

2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each integer in nums will appear twice, only two integers will appear once.
*/