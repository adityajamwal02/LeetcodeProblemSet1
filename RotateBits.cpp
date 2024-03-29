/*
Given an integer N and an integer D, rotate the binary representation of the integer N by D digits to the left as well as right and print the results in decimal values after each of the rotation.
Note: Integer N is stored using 16 bits. i.e. 12 will be stored as 0000.....001100.

Example 1:

Input:
N = 28, D = 2
Output:
112
7
Explanation: 28 in Binary is:
000...011100
Rotating left by 2 positions, it becomes
00...1110000 = 112 (in decimal).
Rotating right by 2 positions, it becomes
000...000111 = 7 (in decimal).

​Example 2:

Input:
N = 29, D = 2
Output:
116
16391
Explanation: 29 in Binary is:
000...011101
Rotating left by 2 positions, it becomes
00...1110100 = 116 (in decimal).
Rotating right by 2 positions, it becomes
010...000111 = 16391 (in decimal).

Your Task:
You don't need to read input or print anything. Your task is to complete the function rotate() which takes the integer N and integer D as inputs and returns an array of size 2 where arr[0] = Decimal value after left rotation and arr[1] = Decimal value after right rotation.


Expected Time Complexity: O(1).
Expected Auxiliary Space: O(1).
*/


class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            d%=16;
            int ls,rs,a,b;
            ls=(n<<d);
            rs=n>>(16-d);
            a=(rs|ls)&((1<<16)-1);
            rs = (n>>d);
            ls= n<<(16-d);
            b= (rs|ls)&((1<<16)-1);
        return {a,b};
        }
};
