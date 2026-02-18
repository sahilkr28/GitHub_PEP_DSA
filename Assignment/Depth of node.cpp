// Given a binary tree of size n, find the depth of the deepest odd-level leaf node in a binary tree. If there is no leaf at the odd level then return 0. Consider that the level starts with 1. The depth of a leaf node is a number of nodes on the path from root to leaf (including both leaf and root).

// Examples:

// Input: 
//           1
//         /    \
//        2      3
//       / \    / \
//      4   5  6   7
// Output: 3
// Explanation: In the above tree 4,5,6 and 7 are odd level leaf nodes at depth 3.So the answer is 3.
// Input: 
//      1
//     / \
//     2   4
// Output: 0
// Explanation: In the above tree,no leaf node is at odd level. So the answer is 0.
// Input: 
//           10
//          /  \
//         5    15
//        / \   
//       3   7     
// Output: 3
// Explanation: In the above tree 3 and 7 are odd level leaf nodes at depth 3. So the answer is 3.
// Constraints:
// 1<=number of nodes<=105
// 1<= node->data <=105

#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    int depthOfOddLeaf(Node *root) {
        // code here
        int maxDepth = 0;
        calculateDepth(root, 1, maxDepth);
        return maxDepth;
    }
private:
    void calculateDepth(Node* node, int level, int& maxDepth) {
        if (!node) return;
        if (level % 2 == 1 && !node->left && !node->right) {
            maxDepth = max(maxDepth, level);
        }
        calculateDepth(node->left, level + 1, maxDepth);
        calculateDepth(node->right, level + 1, maxDepth);
    }
};