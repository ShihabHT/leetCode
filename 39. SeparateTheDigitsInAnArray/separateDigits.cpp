#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        // int elementSum = 0;
        // for(int i = 0; i<numLen; i++) {
        //     elementSum += nums[i];
        // }
        int numLen = nums.size();
        
        vector<int> result;
        for(int j = 0; j < numLen; j++) {
            string strOfNum =to_string(nums[j]);
            int len = strOfNum.size();
            for(int i=0; i < len; i++){
                result.push_back(strOfNum[i]-'0');
                // cout<<strOfNum[i]-'0'<<endl;
            }
        }
        return result;
    }
};

int main(){
    vector<int> nums = {1,15,6,3};
    Solution sol;
    vector<int> result=sol.separateDigits(nums);
    for(int n:result){
        cout <<n<<endl;
    }

    return 0;
}
/*
  2553. Separate the Digits in an Array

Given an array of positive integers nums, return an array answer that consists of the
digits of each integer in nums after separating them in the same order they appear in
nums.
To separate the digits of an integer is to get all the digits it has in the same order.
-For example, for the integer 10921, the separation of its digits is [1,0,9,2,1].
*/