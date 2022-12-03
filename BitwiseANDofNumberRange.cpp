/*
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

Example 1:
Input: left = 5, right = 7
Output: 4

Example 2:
Input: left = 0, right = 0
Output: 0

Example 3:
Input: left = 1, right = 2147483647
Output: 0
*/

/// Brute Solution

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int result=left;
        for(int i=left+1;i<=right;i++){
            result=result&i;
        }
    return result;
    }
};


/// Optimized solution: Counting Different Lower Bits

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int result=0;
        while(left!=right){
            left>>=1;
            right>>=1;
            result++;
        }
    return right<<result;
    }
};
