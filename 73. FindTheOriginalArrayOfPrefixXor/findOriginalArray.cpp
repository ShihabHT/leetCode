#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        /*we tried to minimize auxiliary space usage, so instead of creating new vector we
        inserted a neutral element(0) so the values are not affected before their job is
        finished while performing operations*/
        
        pref.insert(pref.begin(), 0);
        for(auto it = pref.begin(); it != pref.end()-1; it++){
            *it = *it ^ *(it+1);
            // for(auto x : pref){
            //     cout << x << " ";
            // }
            // cout<<endl;
        }
        pref.pop_back();
        return pref;
    }
};

int main(){
    vector<int> pref = {5,2,0,3,1};
    vector<int> res;
    Solution sol;
    res = sol.findArray(pref);
    for(const &i : res){
        cout << i << " ";
    }

    return 0;
}
/*
  2433. Find The Original Array of Prefix Xor
Medium

You are given an integer array pref of size n. Find and return the array arr of size n that satisfies:

pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i].
Note that ^ denotes the bitwise-xor operation.

It can be proven that the answer is unique.

Example 1:

Input: pref = [5,2,0,3,1]
Output: [5,7,2,3,2]
Explanation: From the array [5,7,2,3,2] we have the following:
- pref[0] = 5.
- pref[1] = 5 ^ 7 = 2.
- pref[2] = 5 ^ 7 ^ 2 = 0.
- pref[3] = 5 ^ 7 ^ 2 ^ 3 = 3.
- pref[4] = 5 ^ 7 ^ 2 ^ 3 ^ 2 = 1.
Example 2:

Input: pref = [13]
Output: [13]
Explanation: We have pref[0] = arr[0] = 13.
 

Constraints:

1 <= pref.length <= 105
0 <= pref[i] <= 106
*/