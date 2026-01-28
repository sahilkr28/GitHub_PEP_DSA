// Given an array arr[] and an integer target, determine if there exists a triplet in the array whose sum equals the given target.

// Return true if such a triplet exists, otherwise, return false.

// Examples: 

// Input: arr[] = [1, 4, 45, 6, 10, 8], target = 13
// Output: true 
// Explanation: The triplet {1, 4, 8} sums up to 13.
// Input: arr[] = [1, 2, 4, 3, 6, 7], target = 10
// Output: true 
// Explanation: The triplets {1, 3, 6} and {1, 2, 7} both sum to 10. 
// Input: arr[] = [40, 20, 10, 3, 6, 7], target = 24
// Output: false 
// Explanation: No triplet in the array sums to 24.
// Constraints:
// 3 ≤ arr.size() ≤ 5*103
// 0 ≤ arr[i], target ≤ 105

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool hasTripletSum(vector<int> &arr, int target) {
        int n = arr.size();
        if (n < 3) return false;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = arr[i] + arr[l] + arr[r];

                if (sum == target)
                    return true;
                else if (sum < target)
                    l++;
                else
                    r--;
            }
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
    cout << (obj.hasTripletSum(arr, target) ? "true" : "false");

    return 0;
}
