#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int square(int n){
        int digit, sum = 0;
        while(n>0){
            digit = n%10;
            sum = sum + digit*digit;
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> remember;
        int sum;
        while(true){
            sum = square(n);
            if(sum == 1) return true;
            else if(remember.count(sum) > 0) return false;
            remember.insert(sum);
            n=sum;
        }
    }
};

int main(){
    Solution sol;
    cout<<sol.isHappy(19)<<endl;

    return 0;
}
/*
  Write an algorithm to determine if a number n is happy.

  A happy number is a number defined by the following process:

  1. Starting with any positive integer, replace the number by the sum of the squares
     of its digits.
  2. Repeat the process until the number equals 1 (where it will stay), or it loops
     endlessly in a cycle which does not include 1.
  3. Those numbers for which this process ends in 1 are happy.
  Return true if n is a happy number, and false if not.
*/