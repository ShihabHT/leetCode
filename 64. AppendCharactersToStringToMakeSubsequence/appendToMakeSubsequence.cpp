#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int tLen = t.size(), position = 0;
        int findFrom = -1;
        while(position<tLen){
            findFrom = s.find(t[position], findFrom+1);
            if(findFrom == -1) break;
            position++;
        }
        return tLen-position;
    }
};

int main(){
    vector<string> words = {"a","bb","acd","ace"};
    Solution sol;
    cout<<sol.appendCharacters("z", "abcde");

    return 0;
}
/*
  2486. Append Characters to String to Make Subsequence
Medium
You are given two strings s and t consisting of only lowercase English letters.

Return the minimum number of characters that need to be appended to the end of s so that t
becomes a subsequence of s.
A subsequence is a string that can be derived from another string by deleting some or no
characters without changing the order of the remaining characters.

Example 1:

Input: s = "coaching", t = "coding"
Output: 4
Explanation: Append the characters "ding" to the end of s so that s = "coachingding".
Now, t is a subsequence of s ("coachingding").
It can be shown that appending any 3 characters to the end of s will never make t a subsequence.
*/