class Solution {
public:
    void findPath(TreeNode* root, int &ans, long long target, long long value) {
        if (!root) return;
        value += root->val;
        if (value == target) ans += 1;
        findPath(root->right, ans, target, value);
        findPath(root->left, ans, target, value);
    }

    void pathSumEveryNode(TreeNode* root, int targetSum, int &ans) {
        if (!root) return;
        findPath(root, ans, targetSum, 0);
        pathSumEveryNode(root->left, targetSum, ans);
        pathSumEveryNode(root->right, targetSum, ans);
    }

    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        pathSumEveryNode(root, targetSum, ans);
        return ans;
    }
};