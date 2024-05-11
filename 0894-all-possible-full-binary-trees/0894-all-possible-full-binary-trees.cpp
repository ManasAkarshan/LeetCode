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
    vector<TreeNode*> solve(int n){
        if(n%2 == 0) return {};

        if(n == 1) {
            TreeNode* nn = new TreeNode(0);
            return {nn};
        }

        vector<TreeNode*> result;

        for(int i=1; i<n; i+=2){
            vector<TreeNode*> leftAllBST = solve(i);
            vector<TreeNode*> rightAllBST = solve(n-i-1);


            for(auto l : leftAllBST){
                for(auto r : rightAllBST){
                    TreeNode* nn = new TreeNode(0);
                    nn->left = l;
                    nn->right = r;

                    result.push_back(nn);
                }
            }
        }

        return result;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};