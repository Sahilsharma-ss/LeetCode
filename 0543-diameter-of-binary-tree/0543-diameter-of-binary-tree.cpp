class Solution {
public:
    int ans = 0;

    int height(TreeNode* root) {
        if (!root) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        ans = max(ans, lh + rh);  

        return 1 + max(lh, rh);    
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }
};
