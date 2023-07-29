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
  118. Pascal's Triangle

Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
*/