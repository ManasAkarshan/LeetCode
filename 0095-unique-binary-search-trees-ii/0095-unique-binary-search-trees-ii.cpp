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
    vector<TreeNode*> solve(int start, int end){
        if(start>end) return {NULL};

        if(start == end) {
            TreeNode* nn = new TreeNode(start);
            return {nn};
        }

        vector<TreeNode*> result;

        for(int i=start; i<=end; i++){
            vector<TreeNode*> leftBST = solve(start, i-1);
            vector<TreeNode*> rightBST = solve(i+1, end);

            for(auto l : leftBST){
                for(auto r : rightBST){
                    TreeNode* nn = new TreeNode(i);
                    nn->left = l;
                    nn->right = r;
                    result.push_back(nn);
                }
            }
        }

        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};