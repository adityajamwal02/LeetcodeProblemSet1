/*
N horizontal line segments are arranged on the X-axis of a 2D plane. The start and end point of each line segment is given in a Nx2 matrix lines[ ][ ]. Your task is to find the maximum number of intersections possible of any vertical line with the given N line segments.

Example 1:
Input:
N = 4
lines[][] = {{1,3}, {2,3}, {1,2}, {4,4}}
Output:
3
Explanation:
A vertical line at X = 2 passes through
{1,3}, {2,3}, {1,2}, ie three of the
given horizontal lines.

Example 2:
Input:
N = 3
lines[][] = {{1, 3}, {5, 6}, {3,4}}
Output:
2
Explanation:
A vertical line at X = 3 passes through
two of the given horizontal lines which
is the maximum possible.
Your Task:
You dont need to read input or print anything. Complete the function maxIntersections() which takes the 2D Matrix lines[][] and the integer N as input parameters, and returns the maximum intersections possible.

Expected Time Complexity: O(N*log(N))
Expected Auxiliary Space: O(N)
*/

/// PrefixSum + OrderedMap

// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        map<int,int> mp;
        for(auto it : lines){
            int u=it[0];
            int v=it[1]+1;
            mp[u]++, mp[v]--;
        }
        int ans=0, sum=0;
        for(auto i : mp){
            sum+=i.second;
            ans=max(ans,sum);
        }
    return ans;
    }
};
