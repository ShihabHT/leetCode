#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string hunds(int num){
        string result="";
        vector<string> twoDigit = {"", "One ", "Two ", "Three ", "Four ", "Five ",
                                    "Six ", "Seven ", "Eight ", "Nine ", "Ten ",
                                    "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ",
                                    "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
            
        vector<string> tenTh = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ",
                                "Sixty ", "Seventy ", "Eighty ", "Ninety "};
        // vector<string> hundTh = {"", "One Hundred ", "Two Hundred ", "Three Hundred ", "Four Hundred ", "Five Hundred ", "Six Hundred ", "Seven Hundred ", "Eight Hundred ",};
        
        vector<vector<string>> parent = {twoDigit, tenTh}; 
        int digit, count = 0;
        int thousandthDigit = num / 100;
        num = num % 100;
        
        while(num > 0){
            digit = num % 10;
            if(num < 20 && num >=10) result = parent[0][num] + result;
            else if(digit!=0){
                result = parent[count][digit] + result;
            }
            count++;
            num /= 10;
        }
        if(thousandthDigit!=0) result = twoDigit[thousandthDigit]+"Hundred " + result;
        return result;
    }
    string numberToWords(int num) {
        string result="";
        if(num == 0){
            result = "Zero"+result;
            return result;
        }
        vector<string> millBill = {"", "Thousand ", "Million ", "Billion "};
        int threeDigit, count = 0;
        while(num>0){
            threeDigit = num % 1000;
            result = hunds(threeDigit) + millBill[count] + result;
            count++;
            num /= 1000;
        }
        
        return result.substr(0, result.size()-1);
    }
};

int main(){
    int num = 2147483647;

    Solution sol;
    cout<<sol.numberToWords(num);

    return 0;
}