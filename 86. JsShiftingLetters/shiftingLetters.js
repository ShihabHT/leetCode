/**
 * @param {string} s
 * @param {number[]} shifts
 * @return {string}
 */
var shiftingLetters = function(s, shifts) {
    let total = 0;
    for(let i = 0; i < shifts.length; i++) {
        total += shifts[i];
    }
    let result = "";
    result += String.fromCharCode(97+(((s.charCodeAt(0)+total)-97)%26));
    for(let i = 1; i < s.length; i++) {
        total -= shifts[i-1];
        result += String.fromCharCode(97+(((s.charCodeAt(i)+total)-97)%26));
    }
    return result;
};
var shifts = [3,5,9];
var s = "abc";
console.log(shiftingLetters(s, shifts));
/*
848. Shifting Letters
Medium

You are given a string s of lowercase English letters and an integer array shifts of the same length.

Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').

For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.

Return the final string after all such shifts to s are applied.

Example 1:
Input: s = "abc", shifts = [3,5,9]
Output: "rpl"
Explanation: We start with "abc".
After shifting the first 1 letters of s by 3, we have "dbc".
After shifting the first 2 letters of s by 5, we have "igc".
After shifting the first 3 letters of s by 9, we have "rpl", the answer.

Example 2:
Input: s = "aaa", shifts = [1,2,3]
Output: "gfd"
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
shifts.length == s.length
0 <= shifts[i] <= 109
*/