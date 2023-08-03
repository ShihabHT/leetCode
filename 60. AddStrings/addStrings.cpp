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
  989. Add to Array-Form of Integer

The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

Example 1:

Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
*/