/*
Given a string S. The task is to find the first repeated character in it. We need to find the character that occurs more than once and whose index of second occurrence is smallest. S contains only lowercase letters.

Example 1:
Input: S="geeksforgeeks"
Output: e
Explanation: 'e' repeats at third position.

Example 2:
Input: S="hellogeeks"
Output: l
Explanation: 'l' repeats at fourth position.

Example 3:
Input: S="abc"
Output: -1
Explanation: There is no repeated character.
Your Task:
You don't need to read input or print anything. Your task is to complete the function firstRepChar() which accepts a string S as input parameter and returns a string containing first repeated character in it. If there is no repeated character in the string S then return "-1".
*/

string firstRepChar(string s)
{
    unordered_map<char,int> mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
        if(mp[s[i]]>1){
            char ch = s[i];
            string result(1,ch);
            return result;
        }
    }
    return "-1";
}
