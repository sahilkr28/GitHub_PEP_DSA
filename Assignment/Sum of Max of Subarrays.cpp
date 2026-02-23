// Given an array arr[], the task is to find the sum of the maximum elements of every possible non-empty sub-arrays of the given array arr[].

// Note: The answer will always fit into 32 bit integer.

// Examples:

// Input: arr[] = [1, 3, 2]
// Output: 15
// Explanation: All possible non-empty subarrays of [1, 3, 2] are [1], [3], [2], [1, 3], [3, 2] and [1, 3, 2]. The maximum elements of the subarrays are 1, 3, 2, 3, 3, 3 respectively. The sum will be 15.
// Input: arr[] = [3, 1]
// Output: 7
// Explanation: All possible non-empty subarrays of [3, 1] are [3], [1] and [3, 1]. The maximum elements of the subarrays are 3, 1, 3 respectively. The sum will be 7.
// Input: arr[] = [8, 0, 1]
// Output: 26
// Explanation: All possible non-empty subarrays of [8, 0, 1] are [8], [0], [1], [8, 0], [0, 1] and [8, 0, 1]. The maximum elements of the subarrays are 8, 0, 1, 8, 1, 8 respectively. The sum will be 26.
// Constraints:
// 1 <= arr.size() <= 104
// 0 <= arr[i] <= 109

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
  public:
    int sumOfMax(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Greater Element (strictly greater)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();

            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater Element (strictly greater)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();

            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans += (long long)arr[i] * left[i] * right[i];
        }

        return (int)ans;
    }
};