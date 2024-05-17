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
    void helper(TreeNode* root,  int k, bool left, TreeNode* par){
        if(!root) return;
        helper(root->left, k, 1, root);
        helper(root->right, k, 0, root);

        if(!root->left && !root->right && root->val == k){
            if(left) par->left = NULL;
            else par->right = NULL;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {

        helper(root->left, target, 1, root);
        helper(root->right, target, 0, root);
        if(!root->left && !root->right && root->val == target) return NULL;

        return root;
    }
};