/*
Given an integer. Find how many structurally unique binary search trees are there that stores the values from 1 to that integer (inclusive).

Example 1:

Input:
N = 2
Output: 2
Explanation:for N = 2, there are 2 unique
BSTs
     1               2
      \            /
       2         1
Example 2:

Input:
N = 3
Output: 5
Explanation: for N = 3, there are 5
possible BSTs
  1           3     3       2     1
    \        /     /      /  \     \
     3      2     1      1    3     2
    /      /       \                 \
   2      1         2                 3


Your Task:
You don't need to read input or print anything. Your task is to complete the function numTrees() which takes the integer N as input and returns the total number of Binary Search Trees possible with keys [1.....N] inclusive. Since the answer can be very large, return the answer modulo 1e9 + 7.

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N).

*/

/// Solved using Catalan's Number

class Solution
{
    public:
    //Function to return the total number of possible unique BST.
    int mod=1e9+7;

    int numTrees(int N)
    {
        long long int dp[N+1];
        dp[0]=dp[1]=1;
        for(int i=2;i<=N;i++){
            dp[i]=0;
            for(int j=0;j<i;j++){
                dp[i]+=dp[j]*dp[i-j-1];
                dp[i]=dp[i]%mod;
            }
        }
    return dp[N];
    }
};
