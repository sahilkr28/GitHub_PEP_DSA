// You are given an array of strings arr[] representing a prefix expression. Your task is to evaluate the expression 
// and return an integer representing its value.

// Note: A prefix expression is of the form "operator operand1 operand2" (e.g., + a b).
// And the division operation between two integers always computes the floor value, i.e floor(5 / 3) = 1 and 
// floor(-5 / 3) = -2.
// It is guaranteed that the result of the expression and all intermediate calculations will fit in a 32-bit 
// signed integer.

// Examples:

// Input: arr[] = ["+", "*", "/", "+", "100", "200", "2", "5", "7"]
// Output: 757
// Explanation: If the expression is converted into an infix expression, it will 
// be ((100 + 200) / 2) * 5 + 7  = 150 * 5 + 7 = 757.
// Input: arr[] = ["^", "+", "2", "3", "2"]
// Output: 25
// Explanation: If the expression is converted into an infix expression, it will be (2 + 3) ^ 2 = 25.
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
    int evaluatePrefix(vector<string>& arr) {
        stack<int> st;
        for(int i = arr.size() - 1; i >= 0; i--) {
            if(arr[i] == "+" || arr[i] == "-" || arr[i] == "*" || arr[i] == "/" || arr[i] == "^") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(arr[i] == "+") {
                    st.push(a + b);
                } else if(arr[i] == "-") {
                    st.push(a - b);
                } else if(arr[i] == "*") {
                    st.push(a * b);
                } else if(arr[i] == "/") {
                    st.push(a / b);
                } else if(arr[i] == "^") {
                    st.push(pow(a, b));
                }
            } else {
                st.push(stoi(arr[i]));
            }
        }
        return st.top();
    }
};