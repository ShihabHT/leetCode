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
    string multiply(string num1, string num2) {
        int num1Len, num2Len = num2.size()-1, carry, sum;
        string result, product = "0";
        int zeros = 0;
        while(num2Len > -1){
            carry = 0;
            result = "";
            num1Len = num1.size()-1;
            while(num1Len > -1 || carry > 0){
                if(num1Len > -1) sum = ((num2[num2Len]-'0') * (num1[num1Len]-'0')) + carry;
                else sum = carry;
                carry = sum / 10;
                result = to_string(sum%10)+result;
                num1Len--;
            }
            for(int i=0; i<zeros; i++){
                result = result + "0";
                cout<< "Zero added : "<<result<<endl;
            }
            zeros++;
            cout << "result : "<<result << endl;
            cout << "product : "<<product << endl;
            product = addStrings(result, product);
            cout << "product after : "<<product << endl;
            num2Len--;
        }
        while(product[0] == '0' && product.size()>1){
            product.erase(0, 1);
            cout << "product after erasing : "<<product << endl;
        }
        return product;
    }
};

int main(){
    Solution sol;
    cout<< sol.multiply("548", "254");

    return 0;
}
/*
  43. Multiply Strings

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
*/