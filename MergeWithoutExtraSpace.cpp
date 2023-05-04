/*
Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

Example 1:
Input:
n = 4, arr1[] = [1 3 5 7]
m = 5, arr2[] = [0 2 6 8 9]
Output:
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
Explanation:
After merging the two
non-decreasing arrays, we get,
0 1 2 3 5 6 7 8 9.

Example 2:
Input:
n = 2, arr1[] = [10, 12]
m = 3, arr2[] = [5 18 20]
Output:
arr1[] = [5 10]
arr2[] = [12 18 20]
Explanation:
After merging two sorted arrays
we get 5 10 12 18 20.

Your Task:
You don't need to read input or print anything. You only need to complete the function merge() that takes arr1, arr2, n and m as input parameters and modifies them in-place so that they look like the sorted merged array when concatenated.

Expected Time Complexity:  O((n+m) log(n+m))
Expected Auxilliary Space: O(1)
*/

/// Extra Space O(n) 2 pointers

class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m)
        {
            int i=n-1, j=0;
            while(i>=0 and j<m){
                if(arr1[i]>arr2[j]){
                    swap(arr1[i],arr2[j]);
                    i--;
                    j++;
                }else{
                    break;
                }
            }
        sort(arr1,arr1+n);
        sort(arr2,arr2+m);
        }
};


/// Gap Method

class Solution{
    public:
        void swapGreater(long long arr1[], long long arr2[], int index1, int index2){
            if(arr1[index1]>arr2[index2]){
                swap(arr1[index1],arr2[index2]);
            }
        }
        void merge(long long arr1[], long long arr2[], int n, int m)
        {
            int len=(m+n);
            int gap=len/2+len%2;
            while(gap>0){
                int left=0, right=left+gap;
                while(right<len){
                    if(left<n and right>=n){
                        swapGreater(arr1,arr2,left,right-n);
                    }else if(left>=n){
                        swapGreater(arr2,arr2,left-n,right-n);
                    }else{
                        swapGreater(arr1,arr1,left,right);
                    }
                    left++, right++;
                }
                if(gap==1) break;
                gap=(gap/2)+(gap%2);
            }
        }
};
