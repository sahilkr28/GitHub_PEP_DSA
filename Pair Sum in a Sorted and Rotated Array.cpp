// Given an array of positive elements arr[] that is sorted and then rotated around an unknown point, 
// the task is to check if the array has a pair with sum equals to a given target.

// Examples:

// Input: arr[] = [7, 9, 1, 3, 5], target = 6
// Output: true
// Explanation: arr[2] and arr[4] has sum equals to 6 which is equal to the target.
// Input: arr[] = [2, 3, 4, 1], target = 3
// Output: true
// Explanation: arr[0] and arr[3] has sum equals to 3 which is equal to the target.
// Input: arr[] = [10, 7, 4, 1], target = 9
// Output: false
// Explanation: There is no such pair exists in arr[] which sums to target.
// Constraints:
// 2 <= arr.size() <=106
// 1 <= arr[i] <= 106
// 1 <= target <= 106

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        int n = arr.size();
        if (n < 2) return false;

        
        int pivot = -1;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                pivot = i;
                break;
            }
        }

        if (pivot == -1)
            pivot = n - 1;

        int l = (pivot + 1) % n; 
        int r = pivot;           

        
        while (l != r) {
            int sum = arr[l] + arr[r];

            if (sum == target)
                return true;
            else if (sum < target)
                l = (l + 1) % n;
            else
                r = (n + r - 1) % n;
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
    cout << (obj.pairInSortedRotated(arr, target) ? "true" : "false");

    return 0;
}
