#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool matches(string &word, string &s){
        int wLen = word.size();
        int position = 1;
        int i = s.find(word[0]); //find function probably works pretty fast
        if(i == -1) return false;
        while(position < wLen){
            i = s.find(word[position], i+1);
            if(i == -1) return false;
            position++;
        }
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        for(string word : words){
            if(matches(word, s)) count++;
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