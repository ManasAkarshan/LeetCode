/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void helper(TreeNode* root, int dir, int depth) {
        // 1->left ko aa rha right ko jaega

        if (!root) return;

        helper(root->left, 1, dir ? 1 : depth + 1);
        helper(root->right, 0, dir ? depth + 1 : 1);

        ans = max(ans, depth);
    }
    int longestZigZag(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return 0;

        helper(root, 1, 0);
        helper(root, 0, 0);

        return ans;
    }
};