#include <iostream>
// #include <string>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        string strOfNum ="";
        int len = s.size();
        for(int i = 0; i < len; i++){
            strOfNum += to_string(s[i]-'`');
        }
        int result = 0;
        for(; k>0; k--){
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
    cout << sol.getLucky("zbax", 2)<<endl;

    return 0;
}