#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int num1Len = num1.size()-1, num2Len = num2.size()-1, carry = 0, sum;
        string result = "";
        while(num1Len > -1 || num2Len > -1 || carry > 0){
            sum = carry;
            if(num1Len>-1){
                sum += num1[num1Len] - '0';
                num1Len--;
            } 
            if(num2Len>-1){
                sum += num2[num2Len] - '0';
                num2Len--;
            }
            carry = sum/10;
            result = to_string(sum%10) + result;
        }
        return result;
    }
};

int main(){
    Solution sol;
    cout<< sol.addStrings("0", "54");

    return 0;
}
/*
  415. Add Strings

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
*/