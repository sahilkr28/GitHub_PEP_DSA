// You are given the root of a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

// Note:

// Return the nodes from the leftmost node to the rightmost node.
// If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view. 
// Examples:

// Input: root = [1, 2, 3]
// Output: [2, 1, 3]
// Explanation: The Green colored nodes represents the top view in the below Binary tree.
 
// Input: root = [10, 20, 30, 40, 60, 90, 100]
// Output: [40, 20, 10, 30, 100]
// Explanation: The Green colored nodes represents the top view in the below Binary tree.


// Constraints:
// 1 ≤ number of nodes ≤ 105
// 1 ≤ node->data ≤ 105

#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        int HD = 0;
        queue<pair<Node*, int>> q;
        map<int, int> mp; //HD , val of node
        q.push({root, HD});
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            Node* front = node.first;
            int hd = node.second;
            //check visiting first time or not
            if(mp.find(hd) == mp.end()){
                mp[hd] = front->data;
            }
            
            if(front->left) q.push({front->left, hd - 1});
            if(front->right) q.push({front->right, hd + 1});
        }    
            for(auto it : mp){
                ans.push_back(it. second);
            }
        
        return ans;
    }
};