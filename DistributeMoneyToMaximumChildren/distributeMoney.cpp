#include <iostream>
using namespace std;

class Solution {
public:
    int distMoney(int money, int children) {
        int result = 0;
        if(children > money || (children==1 && money == 4)) return -1;
        else if(money < 8) return 0;
        money = money - children;
        result = money / 7;

        if(result >= children) result = children;
        if(money%7 == 3 and children - result == 1) return result-1;
        else if(money/7>children and children - result == 0) return result-1;
        else if(money%7>0 and children - result == 0) return result-1;

        return result;
    }
};

int main(){
    Solution sol;
    cout<< sol.distMoney(23, 2);
    return 0;
}
/*
  You are given an integer money denoting the amount of money (in dollars) that you have and
  another integer children denoting the number of children that you must distribute the money to.
  You have to distribute the money according to the following rules:

    *All money must be distributed.
    *Everyone must receive at least 1 dollar.
    *Nobody receives 4 dollars.
  Return the maximum number of children who may receive exactly 8 dollars if you distribute the
  money according to the aforementioned rules. If there is no way to distribute the money, return -1.
*/