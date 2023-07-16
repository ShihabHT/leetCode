#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
    }
};

int main(){
    vector<int> nums1, nums2;

    for(int i=1; i<=10; i+=2){
        nums1.push_back(i);
    }

    for(int i=1; i<=7; i++){
        nums1.push_back(0);
    }

    for(int num : nums1){
        cout<<num<<endl;
    }
    cout << *nums1.begin() << " "<< *(nums1.end()-1)<<endl;

    return 0;
}