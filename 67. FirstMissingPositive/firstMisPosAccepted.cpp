#include <iostream>
#include <vector>
using namespace std;

/*
  the solution lies in the interval [1, len(nums)+1]
  +1 is added because the input could be [1,2,3]. in this case the ans is 4 which is the immediate number after the last number (3)

  This should be accepted
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]<0) nums[i] = 0;
        }
        // for(int x : nums){
        //     cout << x <<" ";
        // }
        // cout<<endl<<endl;
        for(int i = 0; i < nums.size(); i++){
            int x = abs(nums[i])-1; //we added -1 cause we are considering 1-indexed array in this case
            if(0<=x and x<nums.size()){
                if(nums[x]>0) nums[x] *= -1;
                else if(nums[x] == 0) nums[x] = -1*(nums.size()+1);
            }
            // cout<<"After taking action for "<<i+1<<" th element.."<<endl;
            // for(int x : nums){
            //     cout << x <<" ";
            // }
            // cout<<endl;
        }
    /*
     previously i did this, for(int i=1; i<=nums.size()+1; i++) and because of nums.size()+1, i was having an unknow error in leetcode, but this problem doesn't show up
     in visual studio, as it is out of bound and also it was not being executed directly because of the nature of the input, the compiler of visual studio didn't show 
     any error. be careful of these mistakes
    */
        for(int i=1; i<=nums.size(); i++){ 
            if(nums[i-1] >= 0) return i;
        }
        return nums.size()+1;
    }
};

int main(){
    vector<int> nums = {1,-2,2,4,5};
    // for(int x : nums){
    //     cout << x <<" ";
    // }
    // cout<<endl;
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