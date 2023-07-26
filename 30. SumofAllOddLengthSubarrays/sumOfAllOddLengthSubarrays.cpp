#include <iostream>
#include <vector>
using namespace std;
//time limit exceeds with this code
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int size = arr.size(), sum = 0;
        int oddLength = 0;
        while(oddLength < size) {
            for(int j = 0; j < size - oddLength; j++){
                int k = j;
                while(k<=j+oddLength){
                    cout<< arr[k]<<" ";
                    sum = sum+arr[k];
                    k++;
                }
            cout<<endl;
            }
            oddLength += 2;
        }
        return sum;
    }
};

int main(){
    vector<int> arr = {1,2};
    Solution sol;
    cout<<sol.sumOddLengthSubarrays(arr);

    return 0;
}
/*
  Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.
  A subarray is a contiguous subsequence of the array.
*/