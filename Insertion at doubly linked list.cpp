// Given the head of a doubly-linked list, a position p, and an integer x. Add a new node with value x 
// at the position just after pth node in the doubly linked list and return the head of the updated list.

// Note: The position is 0-based indexed.

// Examples:
// Input: p = 2, x = 6
// Output: 2 <-> 4 <-> 5 <-> 6
// Explanation: Insert a node of value 6 after the 2nd node.

// Input: p = 0, x = 44 
// Output: 1 <-> 44 <-> 2 <-> 3 <-> 4
// Explanation: Insert a node of value 44 after the 0th node.

// Constraints:
// 0 ≤ p < list size ≤ 104
// 0 ≤ x, node->data ≤ 104

#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};


class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        Node* curr = head;

        for(int i = 0; i < p; i++) {
            curr = curr->next;
        }

        Node* newNode = new Node(x);

        newNode->next = curr->next;
        newNode->prev = curr;

        if(curr->next != nullptr) {
            curr->next->prev = newNode;
        }

        curr->next = newNode;

        return head;
    }
};