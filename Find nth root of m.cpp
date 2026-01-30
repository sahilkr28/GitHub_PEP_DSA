// You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then return -1.

// Examples :

// Input: n = 3, m = 8
// Output: 2
// Explanation: 23 = 8
// Input: n = 3, m = 9
// Output: -1
// Explanation: 3rd root of 9 is not integer.
// Input: n = 4, m = 16
// Output: 2
// Explanation: 24 = 16
// Constraints:
// 1 ≤ n ≤ 9
// 0 ≤ m ≤ 20

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthRoot(int n, int m) {
        if (m == 0) return 0;

        int low = 1, high = m;

        while (low <= high) {
            long long mid = (low + high) / 2;
            long long val = 1;

            for (int i = 0; i < n; i++) {
                val *= mid;
                if (val > m) break;
            }

            if (val == m)
                return mid;
            else if (val < m)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Solution obj;
    cout << obj.nthRoot(n, m);

    return 0;
}
