/*
Given a binary matrix mat of size n * m, find out the maximum size square sub-matrix with all 1s.

Example 1:
Input: n = 2, m = 2
mat = {{1, 1},
       {1, 1}}
Output: 2
Explaination: The maximum size of the square
sub-matrix is 2. The matrix itself is the
maximum sized sub-matrix in this case.

Example 2:
Input: n = 2, m = 2
mat = {{0, 0},
       {0, 0}}
Output: 0
Explaination: There is no 1 in the matrix.
Your Task:
You do not need to read input or print anything. Your task is to complete the function maxSquare() which takes n, m and mat as input parameters and returns the size of the maximum square sub-matrix of given matrix.
*/


// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        vector<vector<int>> dp(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            dp[i][0]=mat[i][0];
        }
        for(int j=0;j<m;j++){
            dp[0][j]=mat[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j]==0){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
                }
            }
        }
        int answer=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                answer=max(answer, dp[i][j]);
            }
        }
    return answer;
    }
};
