/*
Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

Example 1:
Input: root = [4,2,6,1,3]
Output: 1
Example 2:
Input: root = [1,0,48,null,null,12,49]
Output: 1
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void solve(TreeNode* root, vector<int> &ans){
        if(!root){
            return;
        }
        solve(root->left, ans);
        ans.push_back(root->val);
        solve(root->right, ans);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        int result=INT_MAX, diff=0;
        for(int i=1; i<ans.size();i++){
            diff=ans[i]-ans[i-1];
            if(diff<result){
                result=diff;
            }
        }
    return result;
    }
};
