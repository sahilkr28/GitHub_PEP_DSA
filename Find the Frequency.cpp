// Given an array arr of positive integers and an integer x. Return the frequency of x in the array.

// Examples :

// Input: arr = [1, 1, 1, 1, 1], x = 1
// Output: 5
// Explanation: Frequency of 1 is 5.
// Input: arr = [1, 2, 3, 3, 2, 1], x=2
// Output: 2
// Explanation: Frequency of 2 is 2.
// Constraints:
// 1 <= arr.size() <= 105
// 1 <= arr[i] <= 105
// 1 <= x <= 105

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findFrequency(vector<int> arr, int x) {
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == x) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    int n, x;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> x;

    Solution obj;
    cout << obj.findFrequency(arr, x);

    return 0;
}
