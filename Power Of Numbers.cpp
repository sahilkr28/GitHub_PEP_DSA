// Given a number n, find the value of n raised to the power of its own reverse.
// Note: The result will always fit into a 32-bit signed integer.

// Examples:

// Input: n = 2
// Output: 4
// Explanation: The reverse of 2 is 2, and 22 = 4.
// Input: n = 10
// Output: 10
// Explanation: The reverse of 10 is 1 (leading zero is discarded), and 10 raised to the power 1 is 10.
// Constraints:
// 1 ≤ n ≤ 10

class Solution {
  public:
    int reverseNum(int n) {
        int rev = 0;
        while(n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }
    
    int power(int base, int exp) {
        if(exp == 0) return 1;
        int half = power(base, exp / 2);
        if(exp % 2 == 0)
            return half * half;
        else
            return base * half * half;
    }
    
    int reverseExponentiation(int n) {
        int rev = reverseNum(n);
        return power(n, rev);
    }
};