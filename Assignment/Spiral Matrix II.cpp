// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

// Example 1:
// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]

// Example 2:
// Input: n = 1
// Output: [[1]]

// Constraints:

// 1 <= n <= 20

#include <vector>
using namespace std;    

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         vector<vector<int>> matrix(n, vector<int>(n));
        
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int val = 1;

        while (top <= bottom && left <= right) {
            
            // Move left → right
            for (int j = left; j <= right; j++)
                matrix[top][j] = val++;
            top++;

            // Move top → bottom
            for (int i = top; i <= bottom; i++)
                matrix[i][right] = val++;
            right--;

            // Move right → left
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    matrix[bottom][j] = val++;
                bottom--;
            }

            // Move bottom → top
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    matrix[i][left] = val++;
                left++;
            }
        }

        return matrix;
    }
};