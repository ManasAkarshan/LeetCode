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
    void sum(TreeNode* root, int t, int &ans){
        if(!root) return;

        t = root->val + t*10;   // 4, 
        if(!root->left && !root->right){
            ans += t;
            return;
        }
        sum(root->left, t, ans);
        sum(root->right, t, ans);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        sum(root, 0, ans);
        return ans;
    }
};