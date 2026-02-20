// Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

 

// Example 1:


// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true
// Example 2:


// Input: root = [5,3,6,2,4,null,7], k = 28
// Output: false
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -104 <= Node.val <= 104
// root is guaranteed to be a valid binary search tree.
// -105 <= k <= 105

#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> values;
        inorderTraversal(root, values);
        int left = 0, right = values.size() - 1;
        while (left < right) {
            int sum = values[left] + values[right];
            if (sum == k)
                return true;
            else if (sum < k)
                left++;
            else
                right--;
        }
        return false;
    }
private:
    void inorderTraversal(TreeNode* root, vector<int>& values) {
        if (!root)
            return;
        inorderTraversal(root->left, values);
        values.push_back(root->val);
        inorderTraversal(root->right, values);
    }
};