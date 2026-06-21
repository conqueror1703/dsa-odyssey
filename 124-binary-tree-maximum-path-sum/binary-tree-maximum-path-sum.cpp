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
 i
 */
class Solution {
  

public:
int maxi;
  
int solve(TreeNode* root){
    if(root==NULL) return 0;

    int l=solve(root->left);
    int r=solve(root->right);

    int l_r=l+r+root->val;
    int only_r=root->val;
    int lor=max(l,r)+root->val;

     maxi=max({maxi,lor,only_r,l_r});
    return max(only_r,lor);




}









    int maxPathSum(TreeNode* root) {
         maxi=INT_MIN;
        solve(root);
        return maxi;

        
    }
};