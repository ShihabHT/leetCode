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