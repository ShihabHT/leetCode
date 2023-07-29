#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        if(numRows == 1) return {{1}};
        else{
            result[0] = {1};
            result[1] = {1,1};
        }
        
        for(int i=1; numRows > 2; i++, numRows--){
            vector<int> nums = result[i];
            int len = nums.size();
            vector<int> row(len+1);
            row[0] = 1;
            row[len] = 1;
            for(int i=1; i < len; i++){
                row[i] = nums[i-1]+nums[i];
            }
            result[i+1] = row;
        }
        return result;
    }
};

int main(){
    vector<vector<int>> result;
    Solution sol;
    result = sol.generate(30);
    for(vector<int>  i : result){
        for(int n : i){
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
  2221. Find Triangular Sum of an Array

You are given a 0-indexed integer array nums, where nums[i] is a digit between 0 and 9 (inclusive).
The triangular sum of nums is the value of the only element present in nums after the following
process terminates:

1. Let nums comprise of n elements. If n == 1, end the process. Otherwise, create a new 0-indexed
   integer array newNums of length n - 1.
2. For each index i, where 0 <= i < n - 1, assign the value of newNums[i] as (nums[i] + nums[i+1]) % 10,
   where % denotes modulo operator.
3. Replace the array nums with newNums.
4. Repeat the entire process starting from step 1.
Return the triangular sum of nums.
*/