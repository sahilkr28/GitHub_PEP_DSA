// Given an array arr[] of integers and another integer target. Determine if there exist two distinct indices 
// such that the sum of their elements is equal to the target.

// Examples:

// Input: arr[] = [0, -1, 2, -3, 1], target = -2
// Output: true
// Explanation: arr[3] + arr[4] = -3 + 1 = -2
// Input: arr[] = [1, -2, 1, 0, 5], target = 0
// Output: false
// Explanation: None of the pair makes a sum of 0
// Input: arr[] = [11], target = 11
// Output: false
// Explanation: No pair is possible as only one element is present in arr[]
// Constraints:
// 1 ≤ arr.size ≤ 105
// -105 ≤ arr[i] ≤ 105
// -2*105 ≤ target ≤ 2*105

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        if (n < 2) return false;

        sort(arr.begin(), arr.end());

        int left = 0;
        int right = n - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == target)
                return true;
            else if (sum < target)
                left++;
            else
                right--;
        }

        return false;
    }
};

int main() {
    int n, target;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> target;

    Solution obj;
    cout << (obj.twoSum(arr, target) ? "true" : "false");

    return 0;
}
