#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int carry;
        while(b != 0){
            carry = a & b;
            a ^= b;
            b = static_cast<unsigned int>(carry) << 1;
        }
        return a;
    }
};

int main(){
    Solution sol;
    cout << sol.getSum(1,-1) << endl;

    return 0;
}
/*
  371. Sum of Two Integers

Given two integers a and b, return the sum of the two integers without using the operators + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
*/