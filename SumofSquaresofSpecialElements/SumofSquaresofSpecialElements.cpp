#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum = 0, s = nums.size();
        for(int i = 1; i<=s; i++){
            if(s%i == 0){
                sum = sum + nums[i-1]*nums[i-1];
            }
        }
        return sum;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    Solution sol;
    cout<<sol.sumOfSquares(nums);

    return 0;
}