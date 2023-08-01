#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int total = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j]<0){
                    total  += (cols - j) * (rows - i);
                    cols = j;
                }
            }
        }
        return total;
    }
};

int main(){
    vector<vector<int>> grid = {{ 4, 3, 2,-1},
                                { 3, 2, 1,-1},
                                { 1, 1,-1,-2},
                                {-1,-1,-2,-3}};
    Solution sol;
    cout<<sol.countNegatives(grid)<<endl;

    return 0;
}
/*
  1351. Count Negative Numbers in a Sorted Matrix

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
*/