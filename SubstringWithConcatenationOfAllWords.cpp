/*
You are given a string s and an array of strings words of the same length.
Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once,
in any order, and without any intervening characters.

You can return the answer in any order.

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
*/

class Solution {
public:

    bool checkSubstring(unordered_map<string, int> wordCount, string  s, int wordLen){
        for(int j=0;j<s.size();j+=wordLen){
            string w=s.substr(j, wordLen);
            if(wordCount.find(w)!=wordCount.end()){
                if(--wordCount[w]==-1)
                    return false;
            }
            else{
                return false;
            }
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int sLen=s.size();
        int wordLen=words[0].size();
        int wordsWindow=words.size()*wordLen;

        unordered_map<string, int> wordCount;
        for(int i=0;i<words.size();i++){
            wordCount[words[i]]++;
        }
        int i=0;
        while(i+wordsWindow<=sLen){
            if(checkSubstring(wordCount, s.substr(i, wordsWindow), wordLen)){
                res.push_back(i);
            }
        i++;
        }
    return res;
    }
};
