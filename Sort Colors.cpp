// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the 
// same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]
 
// Constraints:

// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.

// Follow up: Could you come up with a one-pass algorithm using only constant extra space?

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums1);
    cout << "Sorted nums1: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    // Example 2
    vector<int> nums2 = {2, 0, 1};
    sol.sortColors(nums2);
    cout << "Sorted nums2: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;

    // Additional Example 3
    vector<int> nums3 = {0, 1, 0};
    sol.sortColors(nums3);
    cout << "Sorted nums3: ";
    for (int num : nums3) {
        cout << num << " ";
    }
    cout << endl;

    // Additional Example 4
    vector<int> nums4 = {1, 1, 0, 2, 2, 0};
    sol.sortColors(nums4);
    cout << "Sorted nums4: ";
    for (int num : nums4) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
