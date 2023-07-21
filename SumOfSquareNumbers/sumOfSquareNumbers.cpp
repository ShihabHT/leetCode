#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long left=0, right=sqrt(c);
        while(left<=right) {
            long long sum = left*left+right*right;
            if(sum<c) left = left+1;
            else if(sum>c) right = right-1;
            else return true;
        }
        return false;
    }
};

int main(){
    Solution sol;
    cout<<sol.judgeSquareSum(5);

    return 0;
}