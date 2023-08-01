#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLen = s.size(), tLen = t.size(), j=0;
        for(int i = 0; i<tLen and j<sLen; i++){
            cout<<"s["<<j<<"]==t["<<i<<"] : "<< (s[j]==t[i]) <<endl;
            if(s[j]==t[i]) j++;
        }
        return sLen==j;
    }
};

int main(){
    Solution sol;
    cout<<sol.isSubsequence("mim", "mhhabm");

    return 0;
}
/*
  392. Is Subsequence

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
*/