#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long gcd(long long a, long long b) {
        if(b == 0) return a;
        return gcd(b, a%b);
    }
    long long lcm(long long a, long long b){
        return a*b/gcd(a,b);
    }
    long long nthUglyNumber(int n, int a, int b, int c) {
        long long left = 1, right = static_cast<long long>(INT_MAX)*n, mid, count; //don't do "static_cast<long long>(INT_MAX*n)" overflow will occur
        long long ab = lcm(a, b);
        long long ac = lcm(a, c);
        long long bc = lcm(b, c);
        long long abc = lcm(a, bc);
        while(left < right){
            mid = left + (right-left)/2;

            //number of ugly num less than or equal to mid
            count = mid/a + mid/b + mid/c - mid/ab - mid/bc - mid/ac + mid/abc;

            if(count < n) left = mid + 1; //nth ugly num is greater than mid
            else right = mid; //nth ugly num is less than or equal to mid
        }
        return left;
    }
};

int main(){
    Solution sol;
    cout<<sol.nthUglyNumber(1000000000,2,217983653,336916467)<<endl;

    return 0;
}

/*
  An ugly number is a positive integer that is divisible by a, b, or c.
  Given four integers n, a, b, and c, return the nth ugly number.
*/