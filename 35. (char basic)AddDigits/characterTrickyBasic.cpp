#include <iostream>
// #include <string>
using namespace std;

int main(){
    string s = "abc";
    string n = "763";
    cout<<(char)99<<endl;
    cout<<to_string(765)<<" - to_string(765)"<<endl; //converts to string
    cout<<to_string('f')<<" - to_string('f')"<<endl; //but when char is passed it returns its ascii value
    cout<<n[0]-'0'<<" - n[0]-'0'"<<endl; // strOfNum[i] - '0' gives the integer directly(ascii num of int character - ascii num of 0)
    cout<<s[2]-'`'<<" - s[2]-'`'"<<endl; // this gives the number of characters 1 for a, 2 for b and so on
    cout<<s[1]+1<<" - s[1]+1"<<endl; // when int added to char it returns integer
    
    s = "a1b2c1";
    s[1] = s[0]+1; //when replaced into string it automatically converts to string before replacement
    cout<<s<<endl;
    

    return 0;
}