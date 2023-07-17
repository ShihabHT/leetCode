#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> final = {};
        int right = nums.size()-1, left = 0;
        int square1, square2;
        for(int num : nums){
            final.push_back(num*num);
        }
        sort(final.begin(), final.end());
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