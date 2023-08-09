#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0, right = n;
        int top = 0, bottom = n;
        int val = 1;
        vector<vector<int>> res(n, vector<int>(n));
        while(top < bottom && left < right){
            for(int i = left; i < right; i++)
                res[top][i] = val++;
            top++;

            for(int i = top; i < bottom; i++)
                res[i][right-1] = val++;
            right--;

            if(!(top < bottom && left < right)) break;

            for(int i = right-1; i >= left; i--)
                res[bottom-1][i] = val++;
            bottom--;

            for(int i = bottom-1; i>=top; i--)
                res[i][left] = val++;
            left++;
        }
        return res;
    }
};

int main(){
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> res;
    Solution sol;
    matrix = sol.generateMatrix(3);

    for(auto i : matrix){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}
/*
  59. Spiral Matrix II
Medium

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:
Input: n = 1
Output: [[1]]
 
Constraints:
1 <= n <= 20
*/