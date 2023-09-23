#include <iostream>
// #include <string>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        string strOfNum =to_string(num);
        int result = num;
        while(result > 9){
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
    cout << sol.addDigits(2147483647)<<endl;

    return 0;
}
/*
  258. Add Digits
  
  Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
*/