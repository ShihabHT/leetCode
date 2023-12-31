// Fade In and fade out Effect
/**
 * @param {number[]} nums
 * @return {boolean}
 */
// var isMonotonic = function(nums) {
//     var increasing = true;
//     var decreasing = true;

//     for(let i = 0; i < nums.length-1; i++){
//         if(nums[i] > nums[i + 1]) increasing = false;
//         if(nums[i] < nums[i + 1]) decreasing = false;
//     }
//     return increasing || decreasing;
// };

//better performance
var isMonotonic = function(nums) {
    var increasing = nums[0] < nums[nums.length-1];

    for(let i = 0; i < nums.length-1; i++){
        if(increasing && (nums[i] > nums[i + 1])) return false;
        if(!increasing && (nums[i] < nums[i + 1])) return false;
    }
    return true;
};
var nums = [1,2,3,4,53,2];
console.log("Is monotonic? "+isMonotonic(nums));
/**
  896. Monotonic Array
Easy

An array is monotonic if it is either monotone increasing or monotone decreasing.
An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is
monotone decreasing if for all i <= j, nums[i] >= nums[j].
Given an integer array nums, return true if the given array is monotonic, or false otherwise.

Example 1:
Input: nums = [1,2,2,3]
Output: true

Example 2:
Input: nums = [6,5,4,4]
Output: true
Example 3:

Input: nums = [1,3,2]
Output: false
 

Constraints:

1 <= nums.length <= 105
-105 <= nums[i] <= 105
 */