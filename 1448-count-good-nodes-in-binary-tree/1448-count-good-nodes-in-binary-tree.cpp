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
        int search(TreeNode* root,int max)
    {
        if(!root) return 0;
        int count=0;
        if(root->val >= max)
        {
            count +=1;
            max=root->val;
        }
        count+=search(root->left,max);
        count+=search(root->right,max);
        return count;
    }

public:    
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        if(!root->left&&!root->right) return 1;
        int gn = 1;
        gn +=search(root->left,root->val);
        gn +=search(root->right,root->val);
        return gn;
    }
};