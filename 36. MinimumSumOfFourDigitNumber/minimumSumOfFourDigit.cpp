#include <iostream>
using namespace std;

class Solution {
public:
    int minimumSum(int num) {
        string strOfNum =to_string(num);
        string new1;
        new1 = strOfNum[0];
        int pos=0, i=1;
        for(; i < 4; i++){
            if((strOfNum[i]-'0') < (new1[0]-'0')){
                new1 = strOfNum[i];
                pos = i;
            }
        }
        strOfNum.erase(pos, 1);

        string new2;
        new2 = strOfNum[0];
        pos=0;
        i=1;
        for(; i < 3; i++){
            if((strOfNum[i]-'0') < (new2[0]-'0')){
                new2 = strOfNum[i];
                pos = i;
            }
        }
        strOfNum.erase(pos, 1);

        new1 = new1 + strOfNum[0];
        new2 = new2 + strOfNum[1];
        cout<<"new1 : "<<new1<<endl;
        cout<<"new2 : "<<new2<<endl;
        return stoi(new1)+stoi(new2);
    }
};

int main(){
    Solution sol;
    cout << sol.minimumSum(5421)<<endl;

    return 0;
}
/*
  2160. Minimum Sum of Four Digit Number After Splitting Digits

You are given a positive integer num consisting of exactly four digits. Split num
into two new integers new1 and new2 by using the digits found in num. Leading zeros
are allowed in new1 and new2, and all the digits found in num must be used.

For example, given num = 2932, you have the following digits: two 2's, one 9 and one 3.
Some of the possible pairs [new1, new2] are [22, 93], [23, 92], [223, 9] and [2, 329].
Return the minimum possible sum of new1 and new2.
*/