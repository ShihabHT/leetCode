#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        for(auto vec=intervals.begin(); vec!=intervals.end(); vec++) {
            if(newInterval[1]<(*vec)[0]){
                result.push_back(newInterval);
                for(auto it=vec; it!=intervals.end(); it++){
                    result.push_back(*it);
                }
                return result;
            }else if(newInterval[0]>(*vec)[1]){
                result.push_back(*vec);
            }else{
                newInterval[0] = min((*vec)[0], newInterval[0]);
                newInterval[1] = max((*vec)[1], newInterval[1]);
            }
        }
        result.push_back(newInterval);
        return result;
    }
};

int main(){
    vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16},{17,18}};
    vector<int> newInterval = {4,8};
    for(vector<int> vec : intervals) {
        cout << "[";
        for(int x : vec){
            cout<<x<<" ";
        }
        cout << "], ";
    }
    cout << endl;
    Solution sol;
    intervals = sol.insert(intervals, newInterval);
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
/*
  57. Insert Interval
Medium

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi]
represent the start and the end of the ith interval and intervals is sorted in ascending order by
starti. You are also given an interval newInterval = [start, end] that represents the start and
end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti
and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105
*/