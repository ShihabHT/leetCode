#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        while(n > 1){
            int newNumLen = n/2;
            vector<int> newNums(newNumLen);
            for(int i = 0; i < newNumLen; i++){
                if(i&1) {newNums[i] = max(nums[2 * i], nums[2 * i + 1]);cout<<"max : "<<newNums[i]<<endl;}
                else {newNums[i] = min(nums[2 * i], nums[2 * i + 1]);cout<<"min : "<<newNums[i]<<endl;}
            }
            cout<<endl;
            nums = newNums;
            n = nums.size();
        }
        return nums[0];
    }
};

int main(){
    vector<int> nums = {1,3,5,2,4,8,2,2};
    Solution sol;
    cout<<sol.minMaxGame(nums)<<endl;

    return 0;
}
/*
  2293. Min Max Game

You are given a 0-indexed integer array nums whose length is a power of 2.
Apply the following algorithm on nums:

1. Let n be the length of nums. If n == 1, end the process. Otherwise, create a new 0-indexed integer array newNums of length n / 2.
2. For every even index i where 0 <= i < n / 2, assign the value of newNums[i] as min(nums[2 * i], nums[2 * i + 1]).
3. For every odd index i where 0 <= i < n / 2, assign the value of newNums[i] as max(nums[2 * i], nums[2 * i + 1]).
4. Replace the array nums with newNums.
5. Repeat the entire process starting from step 1.
Return the last number that remains in nums after applying the algorithm.
*/