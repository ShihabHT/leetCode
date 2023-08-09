#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, right = matrix[0].size();
        int top = 0, bottom = matrix.size();
        vector<int> res;
        while(top < bottom && left < right){
            for(int i = left; i < right; i++)
                res.push_back(matrix[top][i]);
            top++;

            for(int i = top; i < bottom; i++)
                res.push_back(matrix[i][right-1]);
            right--;

            if(!(top < bottom && left < right)) break;

            for(int i = right-1; i >= left; i--)
                res.push_back(matrix[bottom-1][i]);
            bottom--;

            for(int i = bottom-1; i>=top; i--)
                res.push_back(matrix[i][left]);
            left++;
        }
        return res;
    }
};

int main(){
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> res;
    Solution sol;
    res = sol.spiralOrder(matrix);

    for(auto i : res){
        cout<<i<<" ";
    }

    return 0;
}
/*
  54. Spiral Matrix
Medium

Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/