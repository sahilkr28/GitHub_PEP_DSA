// Problem Description

// You are given K sorted integer arrays in a form of 2D integer matrix A of size K X N.

// You need to merge them into a single array and return it.



// Problem Constraints
// 1 <= K, N <= 103

// 0 <= A[i][j] <= 108

// A[i][j] <= A[i][j+1]



// Input Format
// First and only argument is an 2D integer matrix A.



// Output Format
// Return a integer array denoting the merged array you get after merging all the arrays in A.



// Example Input
// Input 1:

//  A = [  [1, 2, 3]
//         [2, 4, 6]
//         [0, 9, 10]
//      ]


// Example Output
// Output 1:

//  [0, 1, 2, 2, 3, 4, 6, 9, 10]


// Example Explanation
// Explanation 1:

//  You need to merge [1, 2, 3] , [2, 4, 6] and [0, 9, 10]  into a single array
//  so the merged array will look like [0, 1, 2, 2, 3, 4, 6, 9, 10]

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
class Solution {
public:
    vector<int> solve(vector<vector<int>>& A) {
        vector<int> result;
        
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > minHeap;
        
        int K = A.size();
        
        for (int i = 0; i < K; i++) {
            if (!A[i].empty()) {
                minHeap.push(make_tuple(A[i][0], i, 0));
            }
        }
        
        while (!minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            
            int val = get<0>(top);
            int row = get<1>(top);
            int idx = get<2>(top);
            
            result.push_back(val);
            
            if (idx + 1 < A[row].size()) {
                minHeap.push(make_tuple(A[row][idx + 1], row, idx + 1));
            }
        }
        
        return result;
    }
};