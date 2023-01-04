/*
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

Example 1:
Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].

Example 2:
Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
*/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    if(i==0 or j==0)
                        dp[i][j]=1;
                    else
                        dp[i][j]=dp[i-1][j-1]+1;
                    if(ans<dp[i][j])
                        ans=dp[i][j];
                }
            }
        }
    return ans;
    }
};
