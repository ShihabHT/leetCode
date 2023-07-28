#include <iostream>
// #include <string>
using namespace std;

int main(){
    string s = "abc";
    string n = "763";
    cout<<n[0]-'0'<<endl; // strOfNum[i] - '0' gives the integer directly(ascii num of int character - ascii num of 0)
    cout<<s[2]-'`'<<endl; // this gives the number of characters 1 for a, 2 for b and so on

    return 0;
}