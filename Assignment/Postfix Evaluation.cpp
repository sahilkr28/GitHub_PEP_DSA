// You are given an array of strings arr[] that represents a valid arithmetic expression written in Reverse Polish 
// Notation (Postfix Notation). Your task is to evaluate the expression and return an integer representing its value.

// Note: A postfix expression is of the form operand1 operand2 operator (e.g., "a b +"). 
// And the division operation between two integers always computes the floor value, i.e floor(5 / 3) = 1 and 
// floor(-5 / 3) = -2.
// It is guaranteed that the result of the expression and all intermediate calculations will fit in a 32-bit 
// signed integer.

// Examples:

// Input: arr[] = ["2", "3", "1", "*", "+", "9", "-"]
// Output: -4
// Explanation: If the expression is converted into an infix expression, it will be 2 + (3 * 1) – 9 = 5 – 9 = -4.
// Input: arr[] = ["2", "3", "^", "1", "+"]
// Output: 9
// Explanation: If the expression is converted into an infix expression, it will be 2 ^ 3 + 1 = 8 + 1 = 9.
// Constraints:
// 3 ≤ arr.size() ≤ 103
// arr[i] is either an operator: "+", "-", "*", "/" or "^", or an integer in the range [-104, 104]

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;
        for (string s : arr) {
            if (s == "+" || s == "-" || s == "*" || s == "/" || s == "^") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (s == "+") st.push(a + b);
                else if (s == "-") st.push(a - b);
                else if (s == "*") st.push(a * b);
                else if (s == "/") st.push(floor((double)a / b));
                else if (s == "^") st.push(pow(a, b));
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};