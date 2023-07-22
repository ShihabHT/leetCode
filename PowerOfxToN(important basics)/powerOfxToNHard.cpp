#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        if(n<0)x=1/x;
        n=abs(n);
        double ans=1;
        while(n>0){
          if(n&1) ans=x*ans; // n&1, checks if odd
           x*=x;
           n>>=1; // devides by 2 but discards after floating point
        }
       
        return ans;
    }
};

int main(){
    Solution sol;
    cout<<sol.myPow(1.0000000000001, INT_MIN);
    //this solution does not solve this value above

    return 0;
}