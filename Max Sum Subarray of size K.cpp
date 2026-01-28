// Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

// Note: A subarray is a contiguous part of any given array.

// Examples:

// Input: arr[] = [100, 200, 300, 400], k = 2
// Output: 700
// Explanation: arr2 + arr3 = 700, which is maximum.
// Input: arr[] = [1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4
// Output: 39
// Explanation: arr1 + arr2 + arr3 + arr4 = 39, which is maximum.
// Input: arr[] = [100, 200, 300, 400], k = 1
// Output: 400
// Explanation: arr3 = 400, which is maximum.
// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ arr[i] ≤ 106
// 1 ≤ k ≤ arr.size()

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        long long sum = 0;
        for(int i = 0; i < k; i++) sum += arr[i];
        long long maxSum = sum;
        for(int i = k; i < arr.size(); i++) {
            sum += arr[i] - arr[i - k];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};

int main() {
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cin >> k;
    Solution obj;
    cout << obj.maxSubarraySum(arr, k);
    return 0;
}
