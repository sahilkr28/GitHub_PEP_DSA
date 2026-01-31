// You are given a string s, and your task is to reverse the string.

// Examples:

// Input: s = "Geeks"
// Output: "skeeG"
// Input: s = "for"
// Output: "rof"
// Input: s = "a"
// Output: "a"
// Constraints:
// 1 <= s.size() <= 106
// s contains only alphabetic characters (both uppercase and lowercase).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseString(string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};

int main() {
    string s;
    cin >> s;

    Solution obj;
    cout << obj.reverseString(s);

    return 0;
}

