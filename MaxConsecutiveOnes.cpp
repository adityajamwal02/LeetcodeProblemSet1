/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Example 2:
Input: nums = [1,0,1,1,0,1]
Output: 2
*/


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int count=0, maxcount=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                count++;
                maxcount=max(maxcount,count);
            }
            else if(nums[i]==0)
                count=0;

        }
    return maxcount;
    }
};
