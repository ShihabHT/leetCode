#include <iostream>
#include <vector>
using namespace std;

// class NumArray {
// public:
//     vector<int> &n; //reference has been used, so the vector will not be copied
//     NumArray(vector<int>& nums):n(nums){ //this is how to assign value in variable taken as reference
//         for(int i=1; i<n.size(); i++)
//             n[i] += n[i-1];
//     }
//     void update(int index, int val) {
//         int diff;
//         if(index == 0) diff = val - n[index];
//         else diff = (val+n[index-1])-n[index];
//         for(; index < n.size(); index++)
//             n[index] = n[index]+diff;
//     }
    
//     int sumRange(int left, int right) {
//         if(left == 0) return n[right];
//         return n[right]-n[left-1];
//     }
// };
class NumArray {
public:
    int sum = 0;
    vector<int> &n; //reference has been used, so the vector will not be copied
    NumArray(vector<int>& nums):n(nums){
        for(int i = 0; i < nums.size(); i++) sum += nums[i];
    }
    void update(int index, int val) {
        sum -= n[index];
        n[index] = val;
        sum += val;

    }
    
    int sumRange(int left, int right) {
        int res = sum;
        for(int i=0; i < left; i++)
            res -=n[i];
        for(int i=right+1; i < n.size(); i++)
            res -=n[i];
        return res;
    }
};



int main(){
    vector<int> nums = {1,3,5};
    NumArray* obj = new NumArray(nums);
    obj->update(1,2);
    int param_1 = obj->sumRange(0,2);
    cout<<param_1;

    return 0;
}
/*
  303. Range Sum Query - Immutable
Easy

Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and
right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

Example 1:
Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
 

Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105
0 <= left <= right < nums.length
At most 104 calls will be made to sumRange.
*/