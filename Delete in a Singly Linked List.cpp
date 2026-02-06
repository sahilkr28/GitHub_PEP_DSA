// You are given the head of a singly linked list and an integer x. Delete the xth node (1-based indexing) 
// from the singly linked list.

// Examples:

// Input: x = 1,
    
// Output: 2 -> 3 -> 1 -> 7
// Explanation: After deleting the node at the 1st position (1-base indexing), the linked list is as
    
// Input: x = 5,
    
// Output: 2 -> 3 -> 4 -> 5
// Explanation: After deleting the node at 5th position (1-based indexing), the linked list is as
    
// Constraints:
// 1 ≤ size of linked list ≤ 105
// 1 ≤ x ≤ size of linked list

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // code here
        if (head == nullptr)
            return head;

        if (x == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        Node* curr = head;
        for (int i = 1; i < x - 1 && curr->next != nullptr; i++) {
            curr = curr->next;
        }

        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;

        return head;
    }
};