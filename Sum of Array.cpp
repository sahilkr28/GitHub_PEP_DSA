// You are given an integer array arr[]. The task is to find the sum of it.

// Examples:

// Input: arr[] = [1, 2, 3, 4]
// Output: 10
// Explanation: 1 + 2 + 3 + 4 = 10.
// Input: arr[] = [1, 3, 3]
// Output: 7
// Explanation: 1 + 3 + 3 = 7.
// Constraints:
// 1 <= arr.size <= 105
// 1 <= arr[i] <= 104

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // Function to return sum of elements
    int sum(vector<int>& arr, int n){
        if(n <= 0) return 0;
        return arr[n-1] + sum(arr, n-1);
    }
    int arraySum(vector<int>& arr) {
        // code here
        int n = arr.size();
        return sum(arr, n);
    }
};