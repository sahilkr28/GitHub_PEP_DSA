// You are given a matrix mat[][] . Return the boundary traversal on the matrix in a clockwise manner starting 
// from the first row of the matrix.

// Examples:

// Input: mat[][] = [[1, 2, 3, 4],
//                 [5, 6, 7, 8],
//                 [9, 10, 11, 12],
//                 [13, 14, 15,16]]
// Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5]
// Explanation: The boundary traversal is: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5]
// Input:mat[][] = [[12, 11, 10, 9],
//                [8, 7, 6, 5],
//                [4, 3, 2, 1]]
// Output: [12, 11, 10, 9, 5, 1, 2, 3, 4, 8]
// Explanation: The boundary traversal is: [12, 11, 10, 9, 5, 1, 2, 3, 4, 8]
// Input:mat[][] = [[12, 11],
//                 [4, 3]] 
// Output: [12, 11, 3, 4]
// Explanation: The boundary traversal is: [12, 11, 3, 4]
// Constraints:
// 1 ≤ mat.size()≤ 1000
// 1 ≤ mat[0].size() ≤ 1000
// 0 ≤ mat[i][j] ≤ 1000


#include <vector>
using namespace std;
class Solution {
  public:
    vector<int> boundaryTraversal(vector<vector<int>>& mat) {
        // code here
        vector<int> ans;
        int n = mat.size();
        int m = mat[0].size();

        // Top row
        for (int j = 0; j < m; j++)
            ans.push_back(mat[0][j]);

        // Right column
        for (int i = 1; i < n; i++)
            ans.push_back(mat[i][m - 1]);

        // Bottom row (only if more than 1 row)
        if (n > 1) {
            for (int j = m - 2; j >= 0; j--)
                ans.push_back(mat[n - 1][j]);
        }

        // Left column (only if more than 1 column)
        if (m > 1) {
            for (int i = n - 2; i > 0; i--)
                ans.push_back(mat[i][0]);
        }

        return ans;
    }
};
