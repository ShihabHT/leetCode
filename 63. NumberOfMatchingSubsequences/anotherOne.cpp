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
  792. Number of Matching Subsequences
Medium

Given a string s and an array of strings words, return the number of words[i] that is a
subsequence of s.
A subsequence of a string is a new string generated from the original string with some
characters (can be none) deleted without changing the relative order of the remaining
characters.

For example, "ace" is a subsequence of "abcde".
 
Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
*/