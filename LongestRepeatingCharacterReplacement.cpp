/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
*/


class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0, result=0, maxCount=0;
        unordered_map<char,int> mp;
        for(int j=0;j<n;j++){
            mp[s[j]]++;
            maxCount=max(maxCount,mp[s[j]]);
            if((j-i+1)-maxCount > k){
                mp[s[i]]--;
                i++;
            }else{
                result=max(result,j-i+1);
            }
        }
    return result;
    }
};
