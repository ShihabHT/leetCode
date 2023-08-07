#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for(int i=0; i<intervals.size()-1; i++) {
            // cout<<"i : "<<i<<endl;
            if(intervals[i][1]>=intervals[i+1][0]){
                intervals[i][1] = max(intervals[i][1], intervals[i+1][1]);
                intervals.erase(intervals.begin()+i+1);
                i--;
            }
            // cout<<"i : "<<i<<endl;
        }
        return intervals;
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