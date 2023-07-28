#include <iostream>
// #include <string>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        string strOfNum ="";
        int len = s.size();
        for(int i = 0; i < len; i++){
            strOfNum += to_string(s[i]-'`');
        }
        int result = 0;
        for(; k>0; k--){
            cout << "String of Number : "<<strOfNum <<endl;
            int strNumLen = strOfNum.size();
            result = 0;
            for(int i = 0; i < strNumLen; i++){
                cout<<strOfNum[i]-'0'<<endl;
                result += strOfNum[i]-'0'; // strOfNum[i] - '0' gives the integer directly(ascii num of int character - ascii num of 0)
            }
            strOfNum = to_string(result);
        }
        return result;
    }
};

int main(){
    Solution sol;
    cout << sol.getLucky("zbax", 2)<<endl;

    return 0;
}
/*
  1945. Sum of Digits of String After Convert
You are given a string s consisting of lowercase English letters, and an integer k.

First, convert s into an integer by replacing each letter with its position in the alphabet (i.e.,
replace 'a' with 1, 'b' with 2, ..., 'z' with 26). Then, transform the integer by replacing it with
the sum of its digits. Repeat the transform operation k times in total.

For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by the following operations:

1. Convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
2. Transform #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
3. Transform #2: 17 ➝ 1 + 7 ➝ 8
Return the resulting integer after performing the operations described above.
*/