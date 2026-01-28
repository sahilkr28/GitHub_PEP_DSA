// Given an array arr[] of positive integers.The task is to complete the insertsort() function which is used to implement 
// Insertion Sort.

// Examples:

// Input: arr[] = [4, 1, 3, 9, 7]
// Output: [1, 3, 4, 7, 9]
// Explanation: The sorted array will be [1, 3, 4, 7, 9].
// Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
// Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// Explanation: The sorted array will be [1, 2, 3, 4, 5, 6, 7, 8, 9, 10].
// Input: arr[] = [4, 1, 9]
// Output: [1, 4, 9]
// Explanation: The sorted array will be [1, 4, 9].
// Constraints:
// 1 ≤ arr.size() ≤ 1000
// 1 ≤ arr[i] ≤ 10000

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
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
    obj.insertionSort(arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
