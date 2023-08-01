#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0, end=nums.size()-1, mid;
        while(start<=end) {
            mid = start + (end-start)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) end = mid-1;
            else start = mid+1;
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {-1,0,3,5,7,9};
    Solution sol;
    cout << sol.search(nums, -1);

    return 0;
}
/*
  704. Binary Search

Given an array of integers nums which is sorted in ascending order, and an integer
target, write a function to search target in nums. If target exists, then return
its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
*/