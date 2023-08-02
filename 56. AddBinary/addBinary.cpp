#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int aLen = a.size()-1, bLen = b.size()-1, carry = 0, sum;
        string result = "";
        while(aLen > -1 || bLen > -1 || carry > 0){
            sum = carry;
            if(aLen>-1){
                sum += a[aLen] - '0';
                aLen--;
            } 
            if(bLen>-1){
                sum += b[bLen] - '0';
                bLen--;
            } 
            carry = sum/2;
            result = char(sum%2 + '0')+result;
        }
        return result;
    }
};

int main(){
    Solution sol;
    cout<<sol.addBinary("101", "11");

    return 0;
}
/*
  67. Add Binary

Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"
*/