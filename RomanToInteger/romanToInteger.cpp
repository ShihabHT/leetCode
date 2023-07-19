#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string rom) {
        map<char, int> roman = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        
        int s = rom.size(), first =roman[rom[s-1]], second=0, result = first;

        while(s>1) {
            s--;
            second = roman[rom[s-1]];
            if(first>second){
                result = result - second;
                first = second;
            }else {
                result = result + second;
                first = second;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    cout<<sol.romanToInt("MCMXCIV");

    return 0;
}