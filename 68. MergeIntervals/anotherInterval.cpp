#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for(int i=1, j=0; i<intervals.size(); i++) {
            if(result[j][1]>=intervals[i][0]){
                result[j][1] = max(result[j][1], intervals[i][1]);
            }else{
                result.push_back(intervals[i]);
                j++;
            }
            // cout<<"i : "<<i<<endl;
        }
        return result;
    }
};

int main(){
    vector<vector<int>> intervals = {{2,3},{2,2},{3,3},{1,3},{5,7},{2,2},{4,6}};
    for(vector<int> vec : intervals) {
        cout << "[";
        for(int x : vec){
            cout<<x<<" ";
        }
        cout << "], ";
    }
    cout << endl;
    Solution sol;
    intervals = sol.merge(intervals);
    cout<<"ans: "<<endl;
    for(vector<int> vec : intervals) {
        cout << "[";
        for(int x : vec){
            cout<<x<<" ";
        }
        cout << "], ";
    }
    cout << endl;
    return 0;
}