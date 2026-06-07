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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
      //  vector<int>parent(1e5,-1);
        unordered_map<int,TreeNode*>mp;
        unordered_map<int,int>p;
        for(auto i: descriptions)
        {
            int val = i[0];
            int childval = i[1];
            int isleft = i[2];
            TreeNode *node = new TreeNode(val);
            TreeNode *child = new TreeNode(childval);
            if(mp[childval] && mp[val])
            {
                if(isleft)
                {
                    mp[val]->left = mp[childval];
                }
                else
                {
                    mp[val]->right = mp[childval];
                }
                p[childval]--;
                continue;
            }
            if(mp[val])
            {
                if(isleft)
                {
                    mp[val]->left = child;
                }
                else
                {
                    mp[val]->right = child;
                }
                mp[childval] = child;
                if(p[childval]) p[childval]--;
                continue;
            }
            if(mp[childval])
            {
                if(isleft)
                {
                    node->left = mp[childval];
                }
                else
                {
                    node->right = mp[childval];
                }
                mp[val] = node;
                p[val] = 1;
                if(p[childval]) p[childval]--;
                continue;
            }
            if(isleft)
            {
                node->left = child;   
            }
            else
            {
                node->right = child;
            }
          if(p.find(val) == p.end())  p[val] = 1;
           if(p[childval]) p[childval]--;
            mp[val] = node;
            mp[childval] = child;
        }
        for(auto i : p)
        {
            if(i.second==1)
            {
                return mp[i.first];
            }
        }
        return 0;
    }
};