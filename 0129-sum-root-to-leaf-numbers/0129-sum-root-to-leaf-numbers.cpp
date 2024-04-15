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
    int sum(TreeNode* root, int t, int ans){
        if(!root) return 0;

        t = root->val + t*10;  
        if(!root->left && !root->right){
            ans += t;
            return ans;
        }
        int l = sum(root->left, t, ans);
        int r = sum(root->right, t, ans);
        return l+r;
    }
    int sumNumbers(TreeNode* root) {
        return sum(root, 0, 0);
    }
};