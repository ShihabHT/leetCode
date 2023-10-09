#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // GIVES TLE
        // for(int i = 0; i < shifts.size(); i++) {
        //     for(int j = shifts[i][0]; j <= shifts[i][1]; j++) {
        //         s[j] = (s[j] - 'a'+26 + (shifts[i][2]==0? -1:1))%26 + 97;
        //         /*
        //          a lot has been done on one line. s[j] - 'a' to get the num of a characters (0-25, ie. a-z).
        //          26 has been added to compensate for -1. (shifts[i][2]==0? -1:1) has been used to get whether
        //          1 or -1 has to be added. mod 26 to get the nth number for a character. 97 has been added to 
        //          get the ascii number for the character.
        //         */
        //     }
        // }
        int n = s.size();
        vector<int> v(n+1, 0);
        for(int i = 0; i < shifts.size(); i++){
            int l = shifts[i][0];
            int r = shifts[i][1];
            shifts[i][2]==1? (v[l]++, v[r+1]--) :(v[l]--, v[r+1]++);
            /*
                short had else if has been used here. multiple expressions can be written inside braces.
                braces must be used. otherwise unwanted result will occur.
            */
        }
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += v[i];
            s[i] = (s[i] - 'a' + (sum%26)+ 26)%26 + 'a';
            /*
                 a lot has been done on one line. s[j] - 'a' to get the num of a characters (0-25, ie. a-z).
                 26 has been added with (sum%26) to compensate for negative sum. 
                  mod 26 to get the nth number for a character. 97 or 'a' has been added to 
                 get the ascii number for the character.
            */
        }
        return s;
    }
};

int main(){
    vector<vector<int>> shifts = {{0,1,0},{1,2,1},{0,2,1}};
    string s = "abc";

    Solution sol;
    cout<< sol.shiftingLetters(s, shifts);
    // cout<<char(('a'-'`'+2)%26+96);

    return 0;
}
/*
    2381. Shifting Letters II

You are given a string s of lowercase English letters and a 2D integer array shifts where 
shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index
starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward
if directioni = 0.

Shifting a character forward means replacing it with the next letter in the alphabet (wrapping 
around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it 
with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

Return the final string after all such shifts to s are applied.

 
Example 1:
Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
Output: "ace"
Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".

Example 2:
Input: s = "dztz", shifts = [[0,0,0],[1,1,1]]
Output: "catz"
Explanation: Firstly, shift the characters from index 0 to index 0 backward. Now s = "cztz".
Finally, shift the characters from index 1 to index 1 forward. Now s = "catz".
 

Constraints:
1 <= s.length, shifts.length <= 5 * 104
shifts[i].length == 3
0 <= starti <= endi < s.length
0 <= directioni <= 1
s consists of lowercase English letters.
*/

/*
ChatGPT:
This code defines a C++ function called shiftingLetters that takes two parameters:

string s: This is a string that represents an initial sequence of lowercase letters.
vector<vector<int>>& shifts: This is a vector of vectors of integers. Each subvector in shifts contains three 
integers: shifts[i][0], shifts[i][1], and shifts[i][2]. These integers represent a range of characters in the 
string s and a shift value.
The function's goal is to perform shifting operations on the characters in the string s based on the provided 
shifts and return the modified string.

Here's a step-by-step explanation of what the code does:

1. Initialize variables:

- int n = s.size(): This variable stores the length of the input string s.
- int sum = 0: This variable will keep track of the cumulative shift value.
- vector<int> v(n + 1, 0): This vector is used to keep track of the shift values for each character in the 
string. It has one extra element to simplify calculation.

2. Loop through the shifts vector:
- For each entry in the shifts vector, you extract the left index l, right index r, and shift value shifts[i][2].
- If shifts[i][2] is equal to 0, it means you need to decrement the shift value for characters in the range [l, r]
and increment it for characters at r + 1. This is done by modifying the v vector.

3. After processing all the shifts, you have the v vector containing the accumulated shift values for each character
in the string.

4. Loop through the characters in the string s:
- For each character at position i, you add the accumulated shift value sum to the character's index in the alphabet 
(assuming 'a' is 0, 'b' is 1, and so on).
- You calculate k as sum % 26 to ensure that the shift value wraps around within the range of the alphabet.
- You calculate p as (s[i] - 'a' + k + 26) % 26 to find the new character after the shift.
- Finally, you update the character in the string s with the new character calculated as char('a' + p).

5. Return the modified string s, which now contains the characters shifted based on the given instructions in the shifts
vector.

In summary, this code performs character shifting based on a range of shifts specified in the shifts vector and returns
the resulting modified string.



Q : explain accumulated sum

ChatGPT:
In the provided code, the term "accumulated sum" refers to a running total or cumulative sum that keeps track of the sum
of shift values for a sequence of operations or elements. In this specific code, the accumulated sum is used to keep 
track of the cumulative effect of the shifts applied to characters in the input string s. Here's how it works:

1. Initialize a variable called sum to 0. This variable will serve as the accumulator for the sum of shift values.

2. Loop through the shifts vector and process each shift operation:

3. For each shift operation, you update the sum variable based on the shift value specified in shifts[i][2].
4. After processing all the shift operations, the sum variable contains the cumulative effect of all the shifts applied
to the characters in the string s. It represents the net shift value that has been applied to the characters in the string.

5. When modifying each character in the string s based on the accumulated shift, you use the value of sum to determine the
final shift. You calculate k as sum % 26 to ensure that the shift wraps around within the range of the alphabet. This 
means that if sum is a large positive number, it will wrap around to the beginning of the alphabet, ensuring that the
shift remains within the valid lowercase alphabet characters.

In summary, the accumulated sum (sum) is used to keep track of the total shift applied to the characters in the string,
ensuring that each character is shifted correctly according to the cumulative effect of all the specified shifts.
*/