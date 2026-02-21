// You are given the root of a BST and an integer key. You need to find the inorder predecessor and successor of the given key. If either predecessor or successor is not found, then set it to NULL.

// Note: In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 

// Examples :

// Input: root = [50, 30, 70, 20, 40, 60, 80], key = 65

// Output: [60, 70]
// Explanation: In the given BST the inorder predecessor of 65 is 60 and inorder successor of 65 is 70.

// Input: root = [8, 1, 9, N, 4, N, 10, 3], key = 8

// Output: [4, 9]
// Explanation: In the given BST the inorder predecessor of 8 is 4 and inorder successor of 8 is 9.

// Constraints: 
// 1 ≤ no. of nodes ≤ 105
// 1 ≤ node->data ≤ 106
// 1 ≤ key ≤ 106

#include <iostream>
#include <vector>
using namespace std;
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pre = NULL;
        Node* suc = NULL;
        Node* current = root;

        while (current != NULL) {
            if (current->data == key) {
                // Found the key
                if (current->left != NULL) {
                    Node* temp = current->left;
                    while (temp->right != NULL) {
                        temp = temp->right;
                    }
                    pre = temp;
                }

                if (current->right != NULL) {
                    Node* temp = current->right;
                    while (temp->left != NULL) {
                        temp = temp->left;
                    }
                    suc = temp;
                }
                break;
            } else if (current->data > key) {
                suc = current;
                current = current->left;
            } else {
                pre = current;
                current = current->right;
            }
        }

        vector<Node*> result;
        result.push_back(pre);
        result.push_back(suc);
        return result;
    }
};