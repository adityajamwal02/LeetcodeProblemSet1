/*
There are n rings and each ring is either red, green, or blue. The rings are distributed across ten rods labeled from 0 to 9.
You are given a string rings of length 2n that describes the n rings that are placed onto the rods.
Every two characters in rings forms a color-position pair that is used to describe each ring where:
The first character of the ith pair denotes the ith ring's color ('R', 'G', 'B').
The second character of the ith pair denotes the rod that the ith ring is placed on ('0' to '9').
For example, "R3G2B1" describes n == 3 rings: a red ring placed onto the rod labeled 3, a green ring placed onto the rod labeled 2,
and a blue ring placed onto the rod labeled 1.
Return the number of rods that have all three colors of rings on them.

Example 1:
Input: rings = "B0B6G0R6R0R6G9"
Output: 1
Explanation:
- The rod labeled 0 holds 3 rings with all colors: red, green, and blue.
- The rod labeled 6 holds 3 rings, but it only has red and blue.
- The rod labeled 9 holds only a green ring.
Thus, the number of rods with all three colors is 1.

Example 2:
Input: rings = "B0R0G0R9R0B0G0"
Output: 1
Explanation:
- The rod labeled 0 holds 6 rings with all colors: red, green, and blue.
- The rod labeled 9 holds only a red ring.
*/


/// Bit Counter Approach (OR)

class Solution {
public:
    int countPoints(string rings) {
        int rods[10] = {};
        for (int i = 0; i < rings.size(); i += 2) {
            int color = rings[i] == 'R' ? 1 : rings[i] == 'G' ? 2 : 4;
            rods[rings[i + 1] - '0'] |= color;
        }
        return count(begin(rods), end(rods), 7);
    }
};




/// Simple Intuitive Approach

class Solution {
public:
    int countPoints(string rings) {
        int n=rings.size();
        vector<set<char>> arr(10);
        for(int i=0;i<n-1;i+=2){
            char ch=rings[i];
            int num=rings[i+1]-'0';
            arr[num].insert(ch);
        }
        int count=0;
        for(int i=0;i<10;i++){
            if(arr[i].size()==3)
                count+=1;
        }
        return count;
    }
};
