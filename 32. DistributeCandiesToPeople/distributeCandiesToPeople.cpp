#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
    This problem can be efficiently solved by using arithmetic series
*/
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people);
        long long terms = (sqrt(1+static_cast<long long>(candies)*8)-1)/2; //number of terms
        // cout<<"terms : "<<terms<<endl;
        long long rows = terms/num_people;
        // cout<<"rows : "<<rows<<endl;
        int columns = num_people;
        // cout<<"columns : "<<columns<<endl;
        int remaining_candies = candies - rows*columns*(rows*columns+1)/2; //sum of natural numbers upto n terms
        // cout<<"remaining_candies : "<<remaining_candies<<endl;
        // cout<<"initial candies : "<<candies<<endl;

        for(int a=1; a<=num_people; a++){
            result[a-1] = static_cast<double>(rows)/2*(2*a+(rows-1)*columns); //sum = (n/2)*(2a + (n-1)*d)
            // cout<<"result "<<a-1<<" : "<<result[a-1]<<endl;
        }
        int lastTerm = 1+(columns*rows-1);
        int i=0;
        for(; remaining_candies>(lastTerm+i); i++){
            result[i] = result[i]+lastTerm+i+1;
            remaining_candies -= lastTerm+i+1;
        }
        result[i] += remaining_candies;
        
        return result;
    }
};

int main(){
    vector<int> result;
    Solution sol;
    result = sol.distributeCandies(1000000000,1000);
    for(int res:result){
        cout<<res<<endl;
    }

    return 0;
}
/*  
    We distribute some number of candies, to a row of n = num_people people in the following way:
    *We then give 1 candy to the first person, 2 candies to the second person, and so on
        until we give n candies to the last person.
    *Then, we go back to the start of the row, giving n + 1 candies to the first person,
        n + 2 candies to the second person, and so on until we give 2 * n candies to the
        last person.
    *This process repeats (with us giving one more candy each time, and moving to the start
        of the row after we reach the end) until we run out of candies.  The last person will
        receive all of our remaining candies (not necessarily one more than the previous gift).
    Return an array (of length num_people and sum candies) that represents the final distribution of candies.
*/