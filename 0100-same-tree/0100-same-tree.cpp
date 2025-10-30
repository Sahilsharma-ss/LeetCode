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
    void dfs(TreeNode *p , vector<int>&vec)
    {
        if(!p) return;
        dfs(p->left,vec);
        vec.push_back(p->val);
        dfs(p->right,vec);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>vec1;
        vector<int>vec2;
        dfs(p,vec1);
        dfs(q,vec2);
        return vec1 == vec2;
    }
};