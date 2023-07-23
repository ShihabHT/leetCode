#define mod 1000000007
#include <iostream>
using namespace std;

class Solution {
public:
    long long power(long long x, long long n){
        long long ans = 1;
        while(n>0){
            if(n&1) ans = (ans*x)%mod;
            x=(x*x)%mod;
            n >>= 1;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = n-odd;

        return static_cast<int>((power(5, even)*power(4, odd))%mod);
    }
};

main(){
    Solution sol;
    cout<<sol.countGoodNumbers(50)<<endl;
    cout<<mod<<endl;

    return 0;
}