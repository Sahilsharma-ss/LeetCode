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
    unordered_map<TreeNode*, int> dp;

    int rob(TreeNode* root) {
        if (!root) return 0;
        if (dp.count(root)) return dp[root];
        int robThis = root->val;
        if (root->left) {
            robThis += rob(root->left->left);
            robThis += rob(root->left->right);
        }
        if (root->right) {
            robThis += rob(root->right->left);
            robThis += rob(root->right->right);
        }
        int skipThis = rob(root->left) + rob(root->right);
        return dp[root] = max(robThis, skipThis);
    }
};
