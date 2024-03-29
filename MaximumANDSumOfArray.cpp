/*
You are given an integer array nums of length n and an integer numSlots such that 2 * numSlots >= n. There are numSlots slots numbered from 1 to numSlots.
You have to place all n integers into the slots such that each slot contains at most two numbers. The AND sum of a given placement is the sum of the bitwise AND of every number with its respective slot number.
For example, the AND sum of placing the numbers [1, 3] into slot 1 and [4, 6] into slot 2 is equal to (1 AND 1) + (3 AND 1) + (4 AND 2) + (6 AND 2) = 1 + 1 + 0 + 2 = 4.
Return the maximum possible AND sum of nums given numSlots slots.

Example 1:
Input: nums = [1,2,3,4,5,6], numSlots = 3
Output: 9
Explanation: One possible placement is [1, 4] into slot 1, [2, 6] into slot 2, and [3, 5] into slot 3.
This gives the maximum AND sum of (1 AND 1) + (4 AND 1) + (2 AND 2) + (6 AND 2) + (3 AND 3) + (5 AND 3) = 1 + 0 + 2 + 2 + 3 + 1 = 9.

Example 2:
Input: nums = [1,3,10,4,7,1], numSlots = 9
Output: 24
Explanation: One possible placement is [1, 1] into slot 1, [3] into slot 3, [4] into slot 4, [7] into slot 7, and [10] into slot 9.
This gives the maximum AND sum of (1 AND 1) + (1 AND 1) + (3 AND 3) + (4 AND 4) + (7 AND 7) + (10 AND 9) = 1 + 1 + 3 + 4 + 7 + 8 = 24.
Note that slots 2, 5, 6, and 8 are empty which is permitted.
*/

/// DP Solution

class Solution {
public:
    int dp[19][(1<<18)-1];
    int helper(int i,int j, int numSlots, vector<int> &nums){
        /// i -> index , j -> mask
        if(i==nums.size()) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int result=0;
        for(int k=0;k<numSlots;k++){
            int firstSlotVacant=j&(1<<(2*k));
            int secondSlotVacant=j&(1<<(2*k+1));
            if(firstSlotVacant==0){
                result=max(result,(nums[i]&(k+1))+helper(i+1,j|1<<(2*k),numSlots,nums));
            }else if(secondSlotVacant==0){
                result=max(result,(nums[i]&(k+1))+helper(i+1,j|1<<(2*k+1),numSlots,nums));
            }
        }
    return dp[i][j]=result;
    }

    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n=nums.size()-1;
        int maxSlot=(1<<(2*numSlots))-1;
        memset(dp,-1,sizeof(dp));
        int ans=helper(0,0,numSlots,nums);
    return ans;
    }
};
