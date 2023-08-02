#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size()-1, carry=0, sum;
        sum = digits[len] + 1;
        digits[len] = sum%10;
        carry = sum/10;
        len--;
        while(len >= 0 && carry > 0){
            sum = digits[len] + carry;
            digits[len] = sum%10;
            carry = sum/10;
            len--;
        }
        if(carry > 0) digits.insert(digits.begin(), carry);
        return digits;
    }
};

int main(){
    vector<int> digits = {9,9,9,9};
    vector<int> result;
    Solution sol;
    result = sol.plusOne(digits);
    for(auto i : result){
        cout<<i<<" "<<endl;
    }

    return 0;
}
/*
  66. Plus One

You are given a large integer represented as an integer array digits, where each
digits[i] is the ith digit of the integer. The digits are ordered from most
significant to least significant in left-to-right order. The large integer does
not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
*/