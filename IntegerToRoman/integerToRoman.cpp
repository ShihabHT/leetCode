#include <iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string result="";
        int numArr[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string Roman[] ={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        int digit, counter = 0;
        while(num!=0) {
            if(num - numArr[counter]>=0){
                result = result + Roman[counter];
                num = num - numArr[counter];
            }else counter++;
        }
        return result;
    }
};

int main(){
    Solution sol;
    cout<<sol.intToRoman(3999);

    return 0;
}