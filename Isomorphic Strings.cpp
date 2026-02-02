// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving 
// the order of characters. No two characters may map to the same character, but a character may map to itself.

// Example 1:

// Input: s = "egg", t = "add"
// Output: true

// Explanation:
// The strings s and t can be made identical by:

// Mapping 'e' to 'a'.
// Mapping 'g' to 'd'.
// Example 2:

// Input: s = "f11", t = "b23"
// Output: false

// Explanation:
// The strings s and t can not be made identical as '1' needs to be mapped to both '2' and '3'.

// Example 3:

// Input: s = "paper", t = "title"
// Output: true

// Constraints:

// 1 <= s.length <= 5 * 104
// t.length == s.length
// s and t consist of any valid ascii character.

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            if (mp1.count(c1)) {
                if (mp1[c1] != c2)
                    return false;
            } else {
                mp1[c1] = c2;
            }

            if (mp2.count(c2)) {
                if (mp2[c2] != c1)
                    return false;
            } else {
                mp2[c2] = c1;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    string s, t;
    cin >> s >> t;

    if (sol.isIsomorphic(s, t))
        cout << "true";
    else
        cout << "false";

    return 0;
}
