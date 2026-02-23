// Given a string s, remove duplicate letters so that every letter appears once and only once. 
// You must make sure your result is the smallest in lexicographical order among all possible results.

// Example 1:
// Input: s = "bcabc"
// Output: "abc"

// Example 2:
// Input: s = "cbacdcbc"
// Output: "acdb"
 
// Constraints:
// 1 <= s.length <= 104
// s consists of lowercase English letters.

#include <iostream>
#include <vector>   
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, -1);
        vector<bool> used(26, false);

        // Record last occurrence
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        string st = "";

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            // Skip if already included
            if (used[c - 'a']) continue;

            // Maintain lexicographical order
            while (!st.empty() &&
                   c < st.back() &&
                   last[st.back() - 'a'] > i) {

                used[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            used[c - 'a'] = true;
        }

        return st;
    }
};