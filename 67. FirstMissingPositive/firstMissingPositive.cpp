#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
  the solution lies in the interval [1, len(nums)+1]
  +1 is added because the input could be [1,2,3]. in this case the ans is 4 which is the immediate number after the last number (3)

  This solution will not be accepted as it has to  run in O(n) time and uses O(1) auxiliary space.
  it runs in O(n) time but takes O(n) auxiliary space
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> unNum;
        for(auto i : nums){
            unNum.insert(i);
        }

    // trying every value of the solution set
        int checkTill = nums.size()+1, i;
        for(i = 1; i<=checkTill; i++){
            if(!unNum.count(i)) break;
        }
        return i;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5};
    Solution sol;
    cout<<sol.firstMissingPositive(nums);

    return 0;
}

/*
  41. First Missing Positive
Hard

Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
*/