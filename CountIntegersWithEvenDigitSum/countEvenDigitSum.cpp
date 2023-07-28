#include <iostream>
using namespace std;

class Solution {
public:
    bool isSumOfTenThEven(int tenTh){
        // cout << tenTh << endl;
        int sum = 0;
        int digit;
        while(tenTh != 0){
            digit = tenTh%10;
            sum += digit;
            tenTh /= 10;
        }
        // cout << sum << endl;
        if(sum&1) return false;
        return true;
    }
    int countEven(int num) {
        int calcNum = num+1;
        int result=0;
        if(calcNum%10 == 0) return (calcNum/2)-1;
        int quotient = calcNum/10;
        int tenTh = quotient*10;
        result = (tenTh/2)-1;
        if(isSumOfTenThEven(tenTh)) return result+(num-tenTh)/2+1;
        return result+(num-tenTh+1)/2;
    }
};

int main(){
    Solution sol;
    cout << sol.countEven(22);

    return 0;
}
/*
  Given a positive integer num, return the number of positive integers
  less than or equal to num whose digit sums are even.
  The digit sum of a positive integer is the sum of all its digits.
*/