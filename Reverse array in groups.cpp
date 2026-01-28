// Given an array arr[] of positive integers. Reverse every sub-array group of size k.
// Note: If at any instance, k is greater or equal to the array size, then reverse the entire array. 

// Examples:

// Input: arr[] = [1, 2, 3, 4, 5], k = 3
// Output: [3, 2, 1, 5, 4]
// Explanation: First group consists of elements 1, 2, 3. Second group consists of 4, 5.
// Input: arr[] = [5, 6, 8, 9], k = 5
// Output: [9, 8, 6, 5]
// Explnation: Since k is greater than array size, the entire array is reversed.
// Constraints:
// 1 ≤ arr.size(), k ≤ 105
// 1 ≤ arr[i] ≤ 105

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseInGroups(vector<int> &arr, int k) {
        int n = arr.size();

        if (k >= n) {
            reverse(arr.begin(), arr.end());
            return;
        }

        for (int i = 0; i < n; i += k) {
            int left = i;
            int right = min(i + k - 1, n - 1);

            while (left < right) {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};

int main() {
    int n, k;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> k;

    Solution obj;
    obj.reverseInGroups(arr, k);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
