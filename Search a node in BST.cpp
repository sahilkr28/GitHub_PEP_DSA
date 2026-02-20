// Given the root of a Binary Search Tree and a node value key, find if the node with value key is present in the BST or not.

// Examples:

// Input: root = [6, 2, 8, N, N, 7, 9], key = 8
    
// Output: true
// Explanation: 8 is present in the BST as right child of root.
// Input: root = [16, 12, 18, 10, N, 17, 19], key = 14
    
// Output: false
// Explanation: 14 is not present in the BST
// Constraints:
// 1 ≤ number of nodes ≤ 3*104
// 1 ≤ node->data, key ≤ 109

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool searchBST(TreeNode* root, int key) {
        if (!root)
            return false;
        if (root->val == key)
            return true;
        if (key < root->val)
            return searchBST(root->left, key);
        else
            return searchBST(root->right, key);
    }
};