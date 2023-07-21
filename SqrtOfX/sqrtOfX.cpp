#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int start = 1, end = x, mid, result;
        if(x == 0 || x == 1) return x;
        while(start<=end) {
            mid = start + (end- start)/2;
            if(mid <= x/mid){
                result = mid;
                start = mid + 1;
            }else end = mid - 1;
        }
        return result;
    }
};

int main(){
    Solution sol;
    cout<<sol.mySqrt(10);

    return 0;
}