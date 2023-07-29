#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        if(rowIndex == 0) return {1};
        else result = {1,1};
        
        for(int i=1; rowIndex > 1; i++, rowIndex--){
            int len = result.size();
            vector<int> row(len+1);
            row[0] = 1;
            row[len] = 1;
            for(int i=1; i < len; i++){
                row[i] = result[i-1]+result[i];
            }
            result = row;
        }
        return result;
    }
};

int main(){
    vector<int> result;
    Solution sol;
    result = sol.getRow(33);
    for(int n : result){
        cout << n << " ";
    }

    return 0;
}
/*
119. Pascal's Triangle II

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1

*/