// Given an array, arr of positive integers. Find the third largest element in it. Return -1 if the third largest element is not found.

// Examples:

// Input: arr[] = [2, 4, 1, 3, 5]
// Output: 3
// Explanation: The third largest element in the array [2, 4, 1, 3, 5] is 3.
// Input: arr[] = [10, 2]
// Output: -1
// Explanation: There are less than three elements in the array, so the third largest element cannot be determined.
// Input: arr[] = [5, 5, 5]
// Output: 5
// Explanation: In the array [5, 5, 5], the third largest element can be considered 5, as there are no other distinct elements.
// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)

// Constraints:
// 1 ≤ arr.size ≤ 105
// 1 ≤ arr[i] ≤ 105

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int thirdLargest(vector<int> &arr) {
        int n = arr.size();
        if (n < 3) {
            return -1;
        }

        int first = -1, second = -1, third = -1;

        for (int i = 0; i < n; i++) {
            if (arr[i] > first) {
                third = second;
                second = first;
                first = arr[i];
            }
            else if (arr[i] > second) {
                third = second;
                second = arr[i];
            }
            else if (arr[i] > third) {
                third = arr[i];
            }
        }

        return third;
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
    cout << obj.thirdLargest(arr);

    return 0;
}
