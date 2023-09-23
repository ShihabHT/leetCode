#include <iostream>
using namespace std;

class Solution {
public:
    string replaceDigits(string s) {
        for(int i=1; i<s.length(); i+=2){
            s[i] = s[i-1]+(s[i]-'0'); //s[i]-'0' gives the integer itself, and when we replace a character in string it automatically converts to char and then replaces
            cout<<s[i]<<endl;
        }
        return s;
    }
};

int main(){
    string s = "a1b2c1";
    cout<<s<<endl;

    Solution sol;
    cout<< sol.replaceDigits(s);

    return 0;
}