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
    void add(TreeNode* root, int &ans, int ch){
        if(!root) return;

        add(root->left, ans, 0);
        if(!root->left && !root->right && ch==0) ans += root->val;
        add(root->right, ans, 1);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        add(root, ans, -1);
        return ans;
    }
};