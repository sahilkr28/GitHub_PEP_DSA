// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

// Example 1:

// Input: s = "aba"
// Output: true
// Example 2:

// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.
// Example 3:

// Input: s = "abc"
// Output: false
 
// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindromeRange(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0, r = s.length() - 1;

        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                return isPalindromeRange(s, l + 1, r) ||
                       isPalindromeRange(s, l, r - 1);
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    string s;
    cin >> s;

    if (sol.validPalindrome(s))
        cout << "true";
    else
        cout << "false";

    return 0;
}
