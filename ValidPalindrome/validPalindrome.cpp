#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size()-1;
        while(start < end) {
            if(!isalnum(s[start])) {start++; continue;}
            if(!isalnum(s[end])) {end--; continue;}
            if(tolower(s[start]) != tolower(s[end])) return false;
            else{
                start++;
                end--;
            }
        }
        return true;
    }
};

int main(){
    string s = "What";
    s.erase(2, 1);
    cout<<s.length()<<endl;
    cout<<s<<endl;
    Solution sol;
    cout<<sol.isPalindrome("A man, a plan, a canal: Panama");

    return 0;
}