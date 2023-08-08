#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> res;
        long long r = 0;
        for(char c : word){
            //this method uses the same process of dividing a number manually on paper
            r = (r*10 + (c-'0'))%m;
            res.push_back(!r ? 1 : 0);
        }
        return res;
    }
};

//Another one
// class Solution {
// public:
//     vector<int> divisibilityArray(string word, int m) {
//         vector<int> res(word.size());
//         long long r = 0;
//         for(int i = 0; i < word.size(); i++) {
//             r = (r*10 + (word[i]-'0'))%m;
//             res[i] = (!r ? 1 : 0);
//         }
//         return res;
//     }
// };

int main(){
    Solution sol;
    vector<int> res = sol.divisibilityArray("998244353",3);
    for(auto i : res){
        cout<<i<<" ";
    }

    return 0;
}