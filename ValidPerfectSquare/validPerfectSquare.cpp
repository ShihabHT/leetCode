#include <iostream>
using namespace std;

// class Solution {
// public:
//     int mySqrt(int x) {
//         int start = 1, end = x, mid, result;
//         if(x == 0 || x == 1) return x;
//         while(start<=end) {
//             mid = start + (end- start)/2;
//             if(mid <= x/mid){
//                 result = mid;
//                 start = mid + 1;
//             }else end = mid - 1;
//         }
//         return result;
//     }
// };
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num, mid;
        while(left<=right){
            mid = left + (right-left)/2;
            // if(mid*mid<num && (mid+1)*(mid+1)> num) return false;
            if(1ll*mid*mid < num) { //This ensures that the mid*mid is calculated using long long
                left = mid+1;
            }else if(1ll*mid*mid > num) {
                right = mid-1;
            }else{
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    cout<<sol.isPerfectSquare(INT_MAX);

    return 0;
}