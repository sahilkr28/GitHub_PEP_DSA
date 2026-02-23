// Given an array arr[]. The task is to sort the array elements by Heap Sort.

// Examples:

// Input: arr[] = [4, 1, 3, 9, 7]
// Output: [1, 3, 4, 7, 9]
// Explanation: After sorting elements using heap sort, elements will be in order as 1, 3, 4, 7, 9.
// Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
// Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// Explanation: After sorting elements using heap sort, elements will be in order as 1, 2, 3, 4, 5, 6, 7, 8, 9, 10.
// Input: arr[] = [2, 1, 5]
// Output: [1, 2, 5]
// Explanation: After sorting elements using heap sort, elements will be in order as 1, 2, 5.
// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ arr[i] ≤ 106

// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

  public:
    void heapSort(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Build Max Heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        // Step 2: Extract elements from heap
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);   // Move max to end
            heapify(arr, i, 0);     // Heapify reduced heap
        }
    }
};