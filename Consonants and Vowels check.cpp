// Let's learn about CPP strings here. CPP strings are quite different from their C counterpart and 
// have various methods that can be invoked on them. We hope you've read the articles.

// You are given a string s containing only lowercase letters. You need to count the number of vowels 
// and the number of consonants.

// If vowel count > consonant count then print - Yes(without quotes).
// If vowel count < consonant count then print - No(without quotes).
// If vowel count = consonant count then print - Same(without quotes).
// Example 1:

// Input:s = "aaaaaa"
// Output:Yes
// Example 2:

// Input:s = "the quick brown fox jumps over the lazy dog"
// Output:No

// Your Task:
// Since this is a function problem, you don't need to take any input. Just complete the function 
// checkString(string s) that take s as input and produces output. In a new line, print the output.

// Constraints:
// 1 <= |s| <= 100

#include <bits/stdc++.h>
using namespace std;

void checkString(string s) {
    int v = 0, c = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || 
                s[i] == 'o' || s[i] == 'u')
                v++;
            else
                c++;
        }
    }

    if (v > c)
        cout << "Yes";
    else if (c > v)
        cout << "No";
    else
        cout << "Same";

    cout << endl;
}

int main() {
    string s;
    getline(cin, s);
    checkString(s);
    return 0;
}

