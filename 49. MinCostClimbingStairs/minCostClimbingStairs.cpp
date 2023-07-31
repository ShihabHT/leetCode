#include <iostream>
#include <vector>
using namespace std;

//The approach is to start at the end and replace each value from the last with the minimum cost required from that position
//Finally return the min of 1st 2 values
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        for(int x = len-3; x >= 0; x--){
            cost[x] += min(cost[x+1], cost[x+2]);
        }
        return min(cost[0], cost[1]);
    }
};

int main(){
    vector<int> cost = {10,15,20};
    Solution sol;
    cout<<"result : "<<sol.minCostClimbingStairs(cost)<<endl;
    cout<<"Vector after running the function : "<<endl;
    for(int x : cost){
        cout << x << " " <<endl;
    }

    return 0;
}
/*
  746. Min Cost Climbing Stairs

You are given an integer array cost where cost[i] is the cost of ith step on a
staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.
*/