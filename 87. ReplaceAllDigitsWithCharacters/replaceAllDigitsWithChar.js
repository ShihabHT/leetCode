/**
 * @param {string} s
 * @param {number[]} shifts
 * @return {string}
 */

var replaceDigits = function(s) {
    let result = "";
    let len = s.length;
    for(let i = 1; i < len; i+=2){
        result += s[i-1] + String.fromCharCode(s.charCodeAt(i-1) + parseInt(s[i]));
    }
    if(len & 1) result += s[len - 1];
    return result;
};
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

var s = "a1b2c1e";
console.log(replaceDigits(s));
console.log(s.charCodeAt(0) + parseInt(s[1]));
/*
1844. Replace All Digits with Characters
Easy

You are given a 0-indexed string s that has lowercase English letters in its even indices and digits in its odd indices.

There is a function shift(c, x), where c is a character and x is a digit, that returns the xth character after c.

For example, shift('a', 5) = 'f' and shift('x', 0) = 'x'.
For every odd index i, you want to replace the digit s[i] with shift(s[i-1], s[i]).

Return s after replacing all digits. It is guaranteed that shift(s[i-1], s[i]) will never exceed 'z'.

Example 1:
Input: s = "a1c1e1"
Output: "abcdef"
Explanation: The digits are replaced as follows:
- s[1] -> shift('a',1) = 'b'
- s[3] -> shift('c',1) = 'd'
- s[5] -> shift('e',1) = 'f'

Example 2:
Input: s = "a1b2c3d4e"
Output: "abbdcfdhe"
Explanation: The digits are replaced as follows:
- s[1] -> shift('a',1) = 'b'
- s[3] -> shift('b',2) = 'd'
- s[5] -> shift('c',3) = 'f'
- s[7] -> shift('d',4) = 'h'
 

Constraints:
1 <= s.length <= 100
s consists only of lowercase English letters and digits.
shift(s[i-1], s[i]) <= 'z' for all odd indices i.
*/