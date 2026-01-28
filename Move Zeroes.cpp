// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]

// Constraints:

// 1 <= nums.length <= 104
// -231 <= nums[i] <= 231 - 1

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[k++] = nums[i];
            }
        }
        while (k < nums.size()) {
            nums[k++] = 0;
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums1);
    for (int x : nums1) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> nums2 = {0};
    sol.moveZeroes(nums2);
    for (int x : nums2) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
