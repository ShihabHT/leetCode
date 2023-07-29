#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        int strLen = s.size();
        while(strLen > k) {
            string newStr = "";
            while(strLen>0){
                int sum = 0;
                if(strLen>k){
                    for(int i=0; i < k; i++){
                        sum += s[i]-'0';
                    }
                    newStr += to_string(sum);
                    s.erase(0, k);
                    cout<<newStr<<endl;
                    cout<<s<<endl;
                }else{
                    for(int i=0; i < strLen; i++){
                        sum += s[i]-'0';
                    }
                    newStr += to_string(sum);
                    s.erase(0, strLen);
                    cout<<newStr<<endl;
                    cout<<s<<endl;
                }
                strLen = s.size();
            }
            s = newStr;
            strLen = s.size();
        }

        return s;
    }
};

int main(){
    Solution sol;
    cout <<sol.digitSum("11111222223", 3)<<endl;

    return 0;
}
/*
  2243. Calculate Digit Sum of a String

You are given a string s consisting of digits and an integer k.

A round can be completed if the length of s is greater than k. In one round, do the
following:
1. Divide s into consecutive groups of size k such that the first k characters are
   in the first group, the next k characters are in the second group, and so on. Note
   that the size of the last group can be smaller than k.
2. Replace each group of s with a string representing the sum of all its digits. For
   example, "346" is replaced with "13" because 3 + 4 + 6 = 13.
3. Merge consecutive groups together to form a new string. If the length of the
   string is greater than k, repeat from step 1.
Return s after all rounds have been completed.
*/