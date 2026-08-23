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
    TreeNode* deleteNode(TreeNode* root, int key) {

        // Node not found
        if (root == nullptr)
            return nullptr;

        // Search left
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }

        // Search right
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        // Found the node
        else {

            // Case 1: no left child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 2: no right child
            if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: two children
            TreeNode *succ = root->right;

            while(succ->left != NULL)
            {
                succ = succ->left;
            }
            root->val = succ->val;
            root->right = deleteNode(root->right,succ->val);
        }

        return root;
    }
};