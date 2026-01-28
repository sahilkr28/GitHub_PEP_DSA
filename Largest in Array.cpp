// Given an array arr[]. The task is to find the largest element and return it.

// Examples:

// Input: arr[] = [1, 8, 7, 56, 90]
// Output: 90
// Explanation: The largest element of the given array is 90.
// Input: arr[] = [5, 5, 5, 5]
// Output: 5
// Explanation: The largest element of the given array is 5.
// Input: arr[] = [10]
// Output: 10
// Explanation: There is only one element which is the largest.
// Constraints:
// 1 <= arr.size()<= 106
// 0 <= arr[i] <= 106

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largest(vector<int> &arr) {
        int lar = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > lar) {
                lar = arr[i];
            }
        }
        return lar;
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
    cout << obj.largest(arr);

    return 0;
}
