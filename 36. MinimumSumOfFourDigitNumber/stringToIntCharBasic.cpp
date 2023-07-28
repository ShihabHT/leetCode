#include <iostream>
using namespace std;


int main(){
    string x = "2";
    string str = "5234";
    cout << x[0]<<endl;
    cout<<"x to int then + 3 : "<<stoi(x)+3<<endl; //convert string to int
    cout<<"str[2] to int then + 3 : "<<stoi(str)+3<<endl; //you can't pass char into stoi
    cout<<"stoi('09') : "<<stoi("09")<<endl;
    if(x[0]>str[0]){ //while comparing they shoule both be char
        cout<<"true"<<endl;
    }
    cout<<"int x[0] = "<<x[0]-'0'<<endl;
    cout<<"int str[0] = "<<str[0]-'0'<<endl;
    x = str[0];  //while assigning value to string of a char of a string, use this
    cout << x << endl;

    return 0;
}
