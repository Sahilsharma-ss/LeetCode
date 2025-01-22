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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return{};
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        double sum=0;
        while(!q.empty())
        {
            int size= q.size();
            sum=0;
            for(int i =0;i<size;i++)
            {
                TreeNode *node = q.front();
                q.pop();
              //  if(sum+(node->val)>INT_MAX) return{};
                sum=sum+(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(sum/(double)size);
        }
        return ans;

    }
};