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
    int ans = 0;
    int solve(TreeNode *root)
    {
        if(!root) return -1e9;
        int lft = -1e9,rht = -1e9;
        if(root->left) lft = solve(root->left);
        if(root->right) rht = solve(root->right);
        if(!root->left && !root->right)
        {
            ans++;
            return root->val;
        }
        if( root->val >= max(lft,rht))
        {
            ans++;
        }
        return max(root->val,max(lft,rht));
    }
    int countDominantNodes(TreeNode* root) {
      solve(root);
      return ans;
    }
};