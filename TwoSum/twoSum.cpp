#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> result={0,1};
        int len = nums.size()-1;
        // while(true){
        //     while(result[1]<=len){
        //         if(nums[result[0]]+nums[result[1]] == target) return result;
        //         result[1]++;
        //     }
        //     result[0]++;
        //     result[1] = result[0] + 1;
        // }

    // With for loop start
        vector<int> result;
        for(int i=0; true; i++){
            for(int j=i+1; j<=len; j++){
                if(nums[i]+nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        // for loop end
    }
};

int main(){
    int target = 19;
    vector<int> nums = {1,18,5,2,17};
    vector<int> result;
    // cout<<result.size()<<endl;
    // cout<<result[0]<<endl;
    // result[1]++;
    // cout<<result[1]<<endl;
    Solution sol;

    result = sol.twoSum(nums, target);
    for(int n : result) {
        cout<<n<<endl;
    }
    return 0;
}