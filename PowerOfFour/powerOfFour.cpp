#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && log2(n)/2 == static_cast<int>(log2(n)/2);
    }
};

int main(){
    Solution sol;
    cout<<sol.isPowerOfFour(256);

    return 0;
}