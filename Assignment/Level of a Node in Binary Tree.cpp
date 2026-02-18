// Given a Binary Tree and a target key, you need to find the level of the target key in the given Binary Tree.

// Note: The level of the root node is 1. If no such key exists then return 0.

// Examples:

// Input: root = [1, 2, 3], target = 4
//         1
//       /   \
//      2     3
// Output: 0
// Input: root = [3, 2, 5, 1, 4], target = 4
//          3
//        /   \
//       2     5
//     /   \
//    1     4
// Output: 3
// Constraints:
// 1 <= number of nodes<= 105
// 1 <= data of a node<= 105
// 1 <= target <= 105

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

class Solution {
  public:
    // function should return level of the target node
    int getLevel(struct Node *node, int target) {
        // code here
        if (!node) return 0;
        if (node->data == target) return 1;
        int leftLevel = getLevel(node->left, target);
        if (leftLevel > 0) return leftLevel + 1;
        int rightLevel = getLevel(node->right, target);
        if (rightLevel > 0) return rightLevel + 1;
        return 0;
    }
};