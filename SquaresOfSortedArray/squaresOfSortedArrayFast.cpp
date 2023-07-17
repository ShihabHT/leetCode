#include <iostream>
#include <vector>
using namespace std;

/*
  insert(final.begin(), 49); this method takes a lot of time so the
  following method is used. with while loop beats 94.26%, in memory
  beats 41.76% with for loop beats 68.76% in memory 66.89%
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> final(nums.size());
        int right = nums.size()-1, left = 0;
        for(int i =right; left != right; i--) {
            if(nums[left]*nums[left]>nums[right]*nums[right]){
                final[i] = nums[left]*nums[left];
                left ++;
            }else{
                final[i] = nums[right]*nums[right];
                right --;
            }
        }
        // int right = nums.size()-1, left = 0, fTotal = right;
        // while(left != right) {
        //     if(nums[left]*nums[left]>nums[right]*nums[right]){
        //         final[fTotal] = nums[left]*nums[left];
        //         left ++;
        //         fTotal --;
        //     }else{
        //         final[fTotal] = nums[right]*nums[right];
        //         right --;
        //         fTotal --;
        //     }
        // }

        final[0] = nums[left]*nums[left];
        return final;
    }
};

int main(){
    vector<int> nums={-7,-3,2,3,11}, nums2;
    cout<<"size of nums: "<<nums.size()<<endl;
    Solution sol;
    nums2 = sol.sortedSquares(nums);
    
    for(int num: nums2){
        cout<<num<<endl;
    }

    return 0;
}