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
    bool helper(TreeNode* root){
        if(!root) return true;
        if(!root->left && !root->right) return root->val;

        int op = root->val;

        bool left = helper(root->left);
        bool right = helper(root->right);

        if(op == 2) return left || right;
        else return left && right;
    }
    bool evaluateTree(TreeNode* root) {
        return helper(root);
    }
};