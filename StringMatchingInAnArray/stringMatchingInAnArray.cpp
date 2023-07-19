#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result = {};
        int wordVecLen = words.size();
        for(int i = 0; i < wordVecLen; i++) {
            for(int j = 0; j < wordVecLen; j++) {
                if(i == j) continue;
                if((words[i].find(words[j]) != string::npos) && (find(result.begin(), result.end(), words[j])==result.end())) result.push_back(words[j]);
            }
        }
        return result;
    }
};

int main(){
    vector<string> words = {"mass","as","hero","superhero"};
        vector<string> result;
    // string str = "kire ki koros";
    // cout<<str.find("koros") << endl;
    // cout<<string::npos << endl;

    // cout<<(find(words.begin(), words.end(), "hero")!=words.end());

    Solution sol;
    result = sol.stringMatching(words);
    for(string word : result){
        cout<<word<<endl;
    }

    return 0;
}