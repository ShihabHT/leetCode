#include <iostream>
#include <vector>
using namespace std;
//time limit exceeds with this code
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int size = arr.size(), sum = 0;
        int oddLength = 0, left, right, multiple;
        while(oddLength < size) {
            left = 0;
            right = size-1;
            multiple = 1;
            while(left <= right) {
                if(multiple > size-oddLength) multiple = size-oddLength;
                else if(multiple > oddLength+1) multiple = oddLength+1;
                if(left != right){
                    cout<<arr[left]<<"+"<<arr[right]<<"*"<<multiple<<" ";
                    sum = sum + (arr[left]+arr[right])*multiple;
                }else{
                    cout<<arr[left]<<"*"<<multiple<<" ";
                    sum = sum + arr[left]*multiple;
                }
                left++;
                right--;
                multiple++;
            }
            cout<<endl;
            oddLength += 2;
        }
        return sum;
    }
};

int main(){
    vector<int> arr = {1,4,2,5,3,6,7};
    Solution sol;
    cout<<sol.sumOddLengthSubarrays(arr);

    return 0;
}
/*
  Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.
  A subarray is a contiguous subsequence of the array.
*/