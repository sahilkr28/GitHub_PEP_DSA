// Given a linked list sorted in ascending order and an integer called key, insert data in the 
// linked list such that the list remains sorted.

// Examples:

// Input: LinkedList: 25->36->47->58->69->80, key: 19
// Output: 19->25->36->47->58->69->80

// Explanation: After inserting 19 the sorted linked list will look like the one in the output.
// Input: LinkedList: 50->100, key: 75
// Output: 50->75->100

// Explanation: After inserting 75 the sorted linked list will look like the one in the output.
// Constraints:
// 1 <= size of linked list <= 106
// 1 <= data of nodes <= 106

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    // Should return head of the modified linked list
    Node* sortedInsert(Node* head, int key) {
        // Code here
        Node* newNode = new Node(key);

        if (head == nullptr || key <= head->data) {
            newNode->next = head;
            return newNode;
        }

        Node* curr = head;
        while (curr->next != nullptr && curr->next->data < key) {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;

        return head;
    }
};