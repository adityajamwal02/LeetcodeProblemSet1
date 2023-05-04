/*
Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers. If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order. You are given an list of numbers arr[ ] of size N.

Example 1:
Input: N = 6
arr = {1, 2, 3, 6, 5, 4}
Output: {1, 2, 4, 3, 5, 6}
Explaination: The next permutation of the
given array is {1, 2, 4, 3, 5, 6}.

Example 2:
Input: N = 3
arr = {3, 2, 1}
Output: {1, 2, 3}
Explaination: As arr[] is the last
permutation. So, the next permutation
is the lowest one.
Your Task:
You do not need to read input or print anything. Your task is to complete the function nextPermutation() which takes N and arr[ ] as input parameters and returns a list of numbers containing the next permutation.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/

// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int index=-1;
        for(int i=N-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1){
            reverse(arr.begin(), arr.end());
            return arr;
        }

        for(int i=N-1;i>=index;i--){
            if(arr[i]>arr[index]){
                swap(arr[i],arr[index]);
                break;
            }
        }
    reverse(arr.begin()+index+1,arr.end());
    return arr;
    }
};