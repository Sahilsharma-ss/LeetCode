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
    int maxi;
   int solve(TreeNode* root)
   {
        if(!root) return 0;
        int lft = solve(root->left);
        int rht = solve(root->right);

        int both_val = lft+rht+root->val;
        int only_one = max(lft,rht) + root->val;
        int only_root = root->val;

        maxi = max({maxi,both_val,only_one,only_root});

        return max(only_one,only_root);
   }
    int maxPathSum(TreeNode* root) {
        maxi = -1e9;
        solve(root);
        return maxi;
    }
};