/*
Given a positive integer n, you can apply one of the following operations:

If n is even, replace n with n / 2.
If n is odd, replace n with either n + 1 or n - 1.
Return the minimum number of operations needed for n to become 1.

Example 1:
Input: n = 8
Output: 3
Explanation: 8 -> 4 -> 2 -> 1

Example 2:
Input: n = 7
Output: 4
Explanation: 7 -> 8 -> 4 -> 2 -> 1
or 7 -> 6 -> 3 -> 2 -> 1

Example 3:
Input: n = 4
Output: 2
*/

/// Recursive

class Solution {
public:
    long long int helper(long long int n){
        if(n==1) return 0;
        if(n%2==0) return 1+helper(n/2);
        else return 1+min(helper(n+1),helper(n-1));
    }
    int integerReplacement(int n) {
        return helper(n);
    }
};

/// Dynamic Solution

class Solution {
public:
	map<int,int>dp;
	int f(long int n){
		if(n==1)return 0;
		if(dp[n]!=0)return dp[n];
		int b=INT_MAX,p=INT_MAX,m=INT_MAX;
		if(n%2==0) b=1+f(n/2);
		else{
			p=1+f(n+1);
			m=1+f(n-1);
		}
		return dp[n]=min(b,min(p,m));
	}

	int integerReplacement(int n) {
		return f(n);
	}
};


