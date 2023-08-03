#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        string b = to_string(k);
        int numLen = num.size()-1, bLen = b.size()-1, carry = 0, sum;
        int resLen = max(numLen, bLen);
        vector<int> result(resLen+1);
        while(numLen > -1 || bLen > -1 || carry > 0){
            sum = carry;
            if(numLen>-1){
                sum += num[numLen];
                numLen--;
            } 
            if(bLen>-1){
                sum += b[bLen] - '0';
                bLen--;
            }
            carry = sum/10;
            if(resLen < 0) result.insert(result.begin(), sum%10); //if we use result.insert() the performace will decline radically
            else result[resLen] = sum%10;
            resLen--;
        }
        return result;
    }
};

int main(){
    vector<int> digits = {2,7,4};
    vector<int> result;
    Solution sol;
    result = sol.addToArrayForm(digits, 981);
    for(auto i : result){
        cout<<i<<" "<<endl;
    }

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