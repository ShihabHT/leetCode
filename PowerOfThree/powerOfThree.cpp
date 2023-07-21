#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 && log10(n)/log10(3) == static_cast<int>(log10(n)/log10(3));
    }
};

int main(){
    Solution sol;
    cout<<sol.isPowerOfThree(128);

    return 0;
}