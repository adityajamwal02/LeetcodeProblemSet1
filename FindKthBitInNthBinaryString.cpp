/*
Given two positive integers n and k, the binary string Sn is formed as follows:
S1 = "0"
Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).
For example, the first four strings in the above sequence are:
S1 = "0"
S2 = "011"
S3 = "0111001"
S4 = "011100110110001"
Return the kth bit in Sn. It is guaranteed that k is valid for the given n.

Example 1:
Input: n = 3, k = 1
Output: "0"
Explanation: S3 is "0111001".
The 1st bit is "0".

Example 2:
Input: n = 4, k = 11
Output: "1"
Explanation: S4 is "011100110110001".
The 11th bit is "1".
*/

class Solution {
public:
    string invert(string str){
        int n=str.size();
        for(int i=0;i<n;i++){
            if(str[i]=='0'){
                str[i]='1';
            }else{
                str[i]='0';
            }
        }
    return str;
    }

    string reverseString(string str){
        reverse(str.begin(),str.end());
    return str;
    }

    string helper(int n, string str){
        if(n==1) return str+"0";
        string temp = helper(n-1,str);
        string temp1 = invert(temp);
        string temp2 = reverseString(temp1);
    return temp+"1"+temp2;
    }

    char findKthBit(int n, int k) {
       string result = helper(n,"");
    return result[k-1];
    }
};
