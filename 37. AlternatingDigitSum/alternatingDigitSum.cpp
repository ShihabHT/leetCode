#include <iostream>
using namespace std;

class Solution {
public:
    int alternateDigitSum(int n) {
        string strOfNum =to_string(n);
        int len = strOfNum.size();
        int sum = 0;
        for(int i=0; i < len; i++){
            if(i&1) sum -= strOfNum[i]-'0';
            else sum += strOfNum[i]-'0';
            cout<<strOfNum[i]-'0'<<endl;
        }
    
        return sum;
    }
};

int main(){
    Solution sol;
    cout << sol.alternateDigitSum(886996)<<endl;

    return 0;
}
/*
  2544. Alternating Digit Sum

You are given a positive integer n. Each digit of n has a sign according to the following rules:

-The most significant digit is assigned a positive sign.
-Each other digit has an opposite sign to its adjacent digits.
Return the sum of all digits with their corresponding sign.
*/