// Given an array arr[], check whether it is sorted in non-decreasing order. Return true if it is sorted otherwise false.

// Examples:

// Input: arr[] = [10, 20, 30, 40, 50]
// Output: true
// Explanation: The given array is sorted.
// Input: arr[] = [90, 80, 100, 70, 40, 30]
// Output: false
// Explanation: The given array is not sorted.
// Constraints:
// 1 ≤ arr.size ≤ 106
// - 109 ≤ arr[i] ≤ 109

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSorted(vector<int>& arr) {
        int n = arr.size();

        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << (obj.isSorted(arr) ? "true" : "false");

    return 0;
}
