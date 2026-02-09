// You are given a Doubly Linked List and an integer x. Remove the node at position x (positions are 1-indexed) 
// from the list, and return the head of the updated list.

// Examples:
// Input: x = 3,   
// Output: 1 <-> 3
// Explanation: After deleting the node at position 3 (position starts from 1), the updated linked list is 1 <-> 3.
   
// Input: x = 1,
// Output: 5 <-> 2 <-> 9
// Explanation: After deleting the node at position 1, the updated linked list is 5 <-> 2 <-> 9.
   
// Constraints:
// 1 ≤ x ≤ size of the linked list ≤ 106
// 0 ≤ node->data ≤ 104

#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // code here
        if (head == NULL) return NULL;

        // Case 1: Delete head node
        if (x == 1) {
            Node* temp = head;
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            delete temp;
            return head;
        }

        // Traverse to the x-th node
        Node* curr = head;
        for (int i = 1; i < x && curr != NULL; i++) {
            curr = curr->next;
        }

        // Adjust pointers if node exists
        if (curr != NULL) {
            if (curr->prev != NULL)
                curr->prev->next = curr->next;

            if (curr->next != NULL)
                curr->next->prev = curr->prev;

            delete curr;
        }

        return head;
    }
};