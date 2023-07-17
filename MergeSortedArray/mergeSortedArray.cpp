#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int total = m+n;
        while(total>0){
            if(n==0){
                return;
            }else if(m==0){
                nums1[total-1]=nums2[n-1];
                n -= 1;
            }else if(nums1[m-1]<nums2[n-1]){
                nums1[total-1] = nums2[n-1];
                n -= 1;
            }else{
                nums1[total-1] = nums1[m-1];
                m -= 1;
            }
            total -= 1;
        }
    }
};

int main(){
    vector<int> nums1, nums2;
    int m=0, n=2;
/*
  push_back() function is used to insert an element at the end of a 
  vector, It does not replace or modify existing elements. Instead,
  it increases the size of the vector and appends the new element to
  the end.
  If you want to modify existing elements in a vector, you can
  directly access them using the indexing operator [] or through
  iterators and then assign a new value to them. Ex, nums1[4]=19
*/
    nums2.push_back(2); 
    nums2.push_back(3);
    nums1.push_back(0);
    nums1.push_back(0);
    for(int num : nums2){
        cout<<num<<endl;
    }
    cout<<"num1 finished..."<<endl;
    // for(int i=1; i<=2*m; i+=2){
    //     nums1.push_back(i);
    // }
    // for(int i=1; i<=n; i++){
    //     nums1.push_back(0);
    // }
    // for(int i=3; i<=3*n; i+=3){
    //     nums2.push_back(i);
    // }
    //cout<<"nums1:"<<endl;
    // for(int num : nums1){
    //     cout<<num<<endl;
    // }
    // cout<<"nums2:"<<endl;
    // for(int num : nums2){
    //     cout<<num<<endl;
    // }
    // cout << *nums1.begin() << " "<< *(nums1.end()-1)<<endl;

    Solution *sol = new Solution();
    sol->merge(nums1, m, nums2, n);
    for(int num: nums1){
        cout << num << endl;
    }

    return 0;
}