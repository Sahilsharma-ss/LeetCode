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
    string ans = "~"; // '~' > 'z', so any string is smaller
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return ans;
    }

    void dfs(TreeNode* root, string s) {
        if (!root) return;
        s.push_back('a' + root->val);

        if (!root->left && !root->right) {
            reverse(s.begin(), s.end());
            ans = min(ans, s);
            return;
        }

        dfs(root->left, s);
        dfs(root->right, s);
    }
};
