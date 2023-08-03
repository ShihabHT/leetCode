#include <iostream>
#include <vector>
using namespace std;

//Gives TLE, find() function gives better performance

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0, sLen = s.size();
        for(string word : words){
            // string word = words[k];
            int wLen = word.size(), j=0;
            for(int i = 0; i<sLen and j<wLen; i++){
                cout<<"word : "<<word<<" : "<<"s["<<i<<"] : "<< (word[j]==s[i]) <<endl;
                if(word[j]==s[i]) j++;
            }
            cout<<endl;
            if(wLen==j) count++;
        }
        return count;
    }
};

int main(){
    vector<string> words = {"a","bb","acd","ace"};
    Solution sol;
    cout<<sol.numMatchingSubseq("abcde", words);

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