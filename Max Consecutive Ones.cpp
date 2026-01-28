// Given a binary array nums, return the maximum number of consecutive 1's in the array.

// Example 1:

// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
// Example 2:

// Input: nums = [1,0,1,1,0,1]
// Output: 2

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int currentCount = 0;
        
        for (int num : nums) {
            if (num == 1) {
                currentCount++;
            } else {
                maxCount = max(maxCount, currentCount);
                currentCount = 0;
            }
        }
        
        return max(maxCount, currentCount);
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 1, 0, 1, 1, 1};
    cout << "Max consecutive 1's in nums1: " << sol.findMaxConsecutiveOnes(nums1) << endl;

    vector<int> nums2 = {1, 0, 1, 1, 0, 1};
    cout << "Max consecutive 1's in nums2: " << sol.findMaxConsecutiveOnes(nums2) << endl;

    vector<int> nums3 = {0, 0, 0, 1, 1, 1, 1};
    cout << "Max consecutive 1's in nums3: " << sol.findMaxConsecutiveOnes(nums3) << endl;

    vector<int> nums4 = {1, 1, 1, 1, 0, 1};
    cout << "Max consecutive 1's in nums4: " << sol.findMaxConsecutiveOnes(nums4) << endl;

    return 0;
}
