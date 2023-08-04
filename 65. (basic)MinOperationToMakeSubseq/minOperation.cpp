#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
/*
for Intuition
https://www.youtube.com/watch?v=0wT67DOzqBg

lower_bound(), upper_bound() basics https://www.youtube.com/watch?v=Tx_u_xZsZOE
*/


class Solution {
public:
    int minOperations(vector<int>& b, vector<int>& c){
        unordered_map<int, int> valToIndx;
        int lenB = b.size();
        for(int i = 0; i < lenB; i++) valToIndx[b[i]] = i;
        vector<int> indexOfC;
        for(int x : c) if(valToIndx.count(x)) indexOfC.push_back(valToIndx[x]);
        vector<int> lenSeq;
        for(int x : indexOfC){
            if(lenSeq.size()==0 || x>lenSeq.back()) lenSeq.push_back(x);
            else *lower_bound(lenSeq.begin(), lenSeq.end(), x)=x;
        }
        return lenB-lenSeq.size();
    }
};

int main(){
    vector<int> target = {16,7,20,11,15,13,10,14,6,8};
    vector<int> arr = {11,14,15,7,5,5,6,10,11,6};
    Solution sol;
    cout<<sol.minOperations(target, arr);

    return 0;
}
/*
  1713. Minimum Operations to Make a Subsequence
Hard

You are given an array target that consists of distinct integers and another integer
array arr that can have duplicates.
In one operation, you can insert any integer at any position in arr. For example, if
arr = [1,4,1,2], you can add 3 in the middle and make it [1,4,3,1,2]. Note that you
can insert the integer at the very beginning or end of the array.

Return the minimum number of operations needed to make target a subsequence of arr.

A subsequence of an array is a new array generated from the original array by deleting
some elements (possibly none) without changing the remaining elements' relative order.
For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements),
while [2,4,2] is not.

Example 1:

Input: target = [5,1,3], arr = [9,4,2,3,4]
Output: 2
Explanation: You can add 5 and 1 in such a way that makes arr = [5,9,4,1,2,3,4], then
target will be a subsequence of arr.
*/