
class Solution {
public:
    int ans = 0;

    pair<int, int> solve(TreeNode* root) {
        if (!root)
            return {0, 0};

        auto left = solve(root->left);
        auto right = solve(root->right);

        int sum = left.first + right.first + root->val;
        int cnt = left.second + right.second + 1;

        if (sum / cnt == root->val) {
            ans++;
        }

        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};

