// Given the root of a binary tree. Your task is to return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

// Note: If the tree is empty, return an empty list.

// Examples :

// Input: root = [1, 2, 3, 4, 5, N, N]

// Output:[1, 2, 4]
// Explanation: From the left side of the tree, only the nodes 1, 2, and 4 are visible.

// Input: root = [1, 2, 3, N, N, 4, N, N, 5, N, N]

// Output: [1, 2, 4, 5]
// Explanation: From the left side of the tree, only the nodes 1, 2, 4, and 5 are visible.

// Constraints:
// 0 ≤ number of nodes ≤ 105
// 0 ≤ node -> data ≤ 105

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        queue<Node*> q;
        vector<int> ans;
        q.push(root);
        if(root == NULL) return ans;
        
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                Node* front = q.front();
                if(i == 0) ans.push_back(front->data);
                q.pop();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }
        return ans;
    }
};