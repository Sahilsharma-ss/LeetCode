class Solution {
public:
    unordered_map<int,int> mp;
    int idx = 0;

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int l, int r)
    {
        if(l > r)
            return NULL;

        int val = preorder[idx++];
        TreeNode* root = new TreeNode(val);

        int pos = mp[val];

        root->left = solve(preorder, inorder, l, pos - 1);
        root->right = solve(preorder, inorder, pos + 1, r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return solve(preorder, inorder, 0, inorder.size() - 1);
    }
};