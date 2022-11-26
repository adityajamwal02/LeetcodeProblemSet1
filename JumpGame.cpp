/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
*/

/// Iterative DP O(n)

class Solution {
public:
    vector<int> dp;
    bool fun(vector<int> &nums, int idx){
        if(idx>=nums.size()){
            return 0;
        }
        if(idx==nums.size()-1){
            return 1;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int k=nums[idx];
        for(int i=1;i<=k;i++){
            if(fun(nums,idx+i)==true){
                return dp[idx]=1;
            }
        }
    return dp[idx]=0;
    }
    bool canJump(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        int idx=0;

    return fun(nums,idx);
    }
};


/// No DP O(n) Same concept

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int last=n-1;
        for(int i=n-2;i>=0;i--){
            if(i+nums[i]>=last){
                last=i;
            }
        }
    return last==0;
    }
};
