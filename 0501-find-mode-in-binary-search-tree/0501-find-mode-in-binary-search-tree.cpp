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
    unordered_map<int,int>mp;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        mp[root->val]++;
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        vector<int>vec;
        for(auto i : mp)
        {
            vec.push_back(i.second);
        }
        int maxi = * max_element(vec.begin(),vec.end());
        vector<int>res;
        for(auto i:mp)
        {
            if(i.second==maxi)
            {
                res.push_back(i.first);
            }
        }
        sort(res.begin(),res.end());
        return res;
       
    }
};