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
    void helper(TreeNode* root, TreeNode* &nr){
        if(!root) return;
        if(!root->left && !root->right) return;

        if(root->right){ 
            nr->left = new TreeNode(root->right->val);
            helper(root->right, nr->left);
        }
        if(root->left){
            nr->right = new TreeNode(root->left->val);
            helper(root->left, nr->right);
        }
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        TreeNode* temp = new TreeNode(root->val);
        helper(root, temp);
        return temp;
    }
};