// Given a root of a Binary Tree, return its boundary traversal in the following order:

// Left Boundary: Nodes from the root to the leftmost non-leaf node, preferring the left child over the right and excluding leaves.

// Leaf Nodes: All leaf nodes from left to right, covering every leaf in the tree.

// Reverse Right Boundary: Nodes from the root to the rightmost non-leaf node, preferring the right child over the left, excluding leaves, and added in reverse order.

// Note: The root is included once, leaves are added separately to avoid repetition, and the right boundary follows traversal preference not the path from the rightmost leaf.

// Examples:

// Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
// Output: [1, 2, 4, 8, 9, 6, 7, 3]
// Explanation:

// Input: root = [1, N, 2, N, 3, N, 4, N, N] 
// Output: [1, 4, 3, 2]
// Explanation:

// Left boundary: [1] (as there is no left subtree)
// Leaf nodes: [4]
// Right boundary: [3, 2] (in reverse order)
// Final traversal: [1, 4, 3, 2]
// Constraints:
// 1 ≤ number of nodes ≤ 105
// 1 ≤ node->data ≤ 105

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    bool isLeaf(Node* node) {
        return !node || (!node->left && !node->right);
    }
    
    void addLeftBoundary(Node* root, vector<int>& result) {
        Node* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) result.push_back(curr->data);
            curr = curr->left ? curr->left : curr->right;
        }
    }
    
    void addLeaves(Node* root, vector<int>& result) {
        if (isLeaf(root)) {
            result.push_back(root->data);
            return;
        }
        if (root->left) addLeaves(root->left, result);
        if (root->right) addLeaves(root->right, result);
    }
    
    void addRightBoundary(Node* root, vector<int>& result) {
        Node* curr = root->right;
        vector<int> temp;
        while (curr) {
            if (!isLeaf(curr)) temp.push_back(curr->data);
            curr = curr->right ? curr->right : curr->left;
        }
        for (int i = temp.size() - 1; i >= 0; i--) {
            result.push_back(temp[i]);
        }
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> result;
        if (!root) return result;
        if (!isLeaf(root)) result.push_back(root->data);
        addLeftBoundary(root, result);
        addLeaves(root, result);
        addRightBoundary(root, result);
        return result;
    }
};