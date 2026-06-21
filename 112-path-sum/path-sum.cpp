class Solution {
public:
    bool solve(TreeNode* root, int target) {
        if (root == NULL) return false;

        if (root->left == NULL && root->right == NULL) {
            return root->val == target;
        }

        return solve(root->left, target - root->val) ||
               solve(root->right, target - root->val);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum);
    }
};