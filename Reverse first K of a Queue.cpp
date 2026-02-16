// Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, 
// leaving the other elements in the same relative order.

// Only following standard operations are allowed on queue.

// enqueue(x) : Add an item x to rear of queue
// dequeue() : Remove an item from front of queue
// size() : Returns number of elements in queue.
// front() : Finds front item.
// Note: The above operations represent the general processings. In-built functions of the respective languages 
// can be used to solve the problem.

// "If the size of queue is smaller than the given k , then return the original queue."

// Examples:

// Input: q = [1, 2, 3, 4, 5], k = 3
// Output: [3, 2, 1, 4, 5]
// Explanation: After reversing the first 3 elements from the given queue the resultant queue will be 3 2 1 4 5
// Input: q = [4, 3, 2, 1], k = 4
// Output: [1, 2, 3, 4] 
// Explanation: After reversing the first 4 elements from the given queue the resultant queue will be 1 2 3 4 
// Constraints:
// 1<=q[i]<=105
// 1<=q.size()<=105
// 1<=k<=105

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        if (q.size() < k) {
            return q;
        }
        stack<int> s;
        for (int i = 0; i < k; i++) {
            s.push(q.front());
            q.pop();
        }
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }
        for (int i = 0; i < q.size() - k; i++) {
            q.push(q.front());
            q.pop();
        }
        return q;
        
    }
};