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
    map<pair<TreeNode*, int>, int> mp;
    int solve(TreeNode* root, int prev){
        if(!root){
            return 0;
        }
        if(mp.find({root, prev}) != mp.end()) return mp[{root, prev}];
        // take
        int take = 0;
        if(prev == 0){
            take += (root->val + solve(root->left, 1) + solve(root->right, 1));
        }

        // notTake
        int notTake = 0;
        notTake = (solve(root->left, 0) + solve(root->right, 0));

        return mp[{root, prev}] = max(take, notTake);
    }
    int rob(TreeNode* root) {
        int take = solve(root, 1);
        int notTake = solve(root, 0);
        return max(take, notTake);
    }
};