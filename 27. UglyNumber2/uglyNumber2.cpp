#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNum(n);
        uglyNum[0] = 1;
        int nextUglyNumber;
        int prime2=0, prime3=0, prime5=0;
        for(int i = 1; i < n; i++) {
            nextUglyNumber = min({uglyNum[prime2]*2, uglyNum[prime3]*3, uglyNum[prime5]*5});
            uglyNum[i] = nextUglyNumber;
            if(uglyNum[prime2]*2==nextUglyNumber) prime2++;
            if(uglyNum[prime3]*3==nextUglyNumber) prime3++;
            if(uglyNum[prime5]*5==nextUglyNumber) prime5++;
        }
        return uglyNum[n-1];
    }
};

int main(){
    Solution sol;
    cout<<sol.nthUglyNumber(10)<<endl;

    return 0;
}

/*
  An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
  Given an integer n, return the nth ugly number.
*/