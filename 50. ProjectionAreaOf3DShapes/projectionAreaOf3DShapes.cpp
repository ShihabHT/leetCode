#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int xy = 0, yz, xz, result = 0;
        int len = grid.size();
        for(int i = 0; i < len; i++){
            yz = 0, xz = 0;
            for(int j = 0; j < len; j++){
                if(grid[i][j]) xy++;
                xz = max(xz, grid[i][j]);
                yz = max(yz, grid[j][i]);
            }
            result += yz + xz;
        }
        return result+xy;
    }
};

int main(){
    vector<vector<int>> grid = {{1,2}, {3,4}};
    Solution sol;
    cout<< sol.projectionArea(grid);

    return 0;
}
/*
  883. Projection Area of 3D Shapes

You are given an n x n grid where we place some 1 x 1 x 1 cubes that are axis-aligned
with the x, y, and z axes.
Each value v = grid[i][j] represents a tower of v cubes placed on top of the cell (i, j).

We view the projection of these cubes onto the xy, yz, and zx planes.
-A projection is like a shadow, that maps our 3-dimensional figure to a 2-dimensional plane.
We are viewing the "shadow" when looking at the cubes from the top, the front, and the side.

Return the total area of all three projections.
*/