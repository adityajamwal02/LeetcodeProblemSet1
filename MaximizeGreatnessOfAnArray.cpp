/*
You are given a 0-indexed integer array nums. You are allowed to permute nums into a new array perm of your choosing.
We define the greatness of nums be the number of indices 0 <= i < nums.length for which perm[i] > nums[i].
Return the maximum possible greatness you can achieve after permuting nums.

Example 1:
Input: nums = [1,3,5,2,1,3,1]
Output: 4
Explanation: One of the optimal rearrangements is perm = [2,5,1,3,3,1,1].
At indices = 0, 1, 3, and 4, perm[i] > nums[i]. Hence, we return 4.

Example 2:
Input: nums = [1,2,3,4]
Output: 3
Explanation: We can prove the optimal perm is [2,3,4,1].
At indices = 0, 1, and 2, perm[i] > nums[i]. Hence, we return 3.
*/

 class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n=nums.size();
        int counter=0;
        sort(nums.begin(), nums.end());
        int i=0, j=1;
        while(j<n){
            if(nums[i]==nums[j]){
                j++;
            }else if(nums[i]<nums[j]){
                counter++;
                j++;
                i++;
            }
        }
    return counter;
    }
};
