#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> final = {};
        int right = nums.size()-1, left = 0;
        while(left != right) {
            if(nums[left]*nums[left]>nums[right]*nums[right]){
                final.insert(final.begin(), nums[left]*nums[left]);
                left += 1;
            }else{
                final.insert(final.begin(), nums[right]*nums[right]);
                right -=1;
            }
        }
        final.insert(final.begin(), nums[left]*nums[left]);
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