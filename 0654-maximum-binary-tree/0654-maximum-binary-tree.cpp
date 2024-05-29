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
    TreeNode* buildTree(vector<int>& nums, int s, int e){
        if(s > e) return NULL;
        pair<int,int> maxi(nums[s], s);

        for(int i=s; i<=e; i++){
            if(nums[i] > maxi.first){
                maxi = make_pair(nums[i], i);
            }
        }


        TreeNode* root = new TreeNode(maxi.first);

        root->left =  buildTree(nums, s, maxi.second-1);
        root->right = buildTree(nums, maxi.second+1, e);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        pair<int,int> maxi(nums[0], 0);

        for(int i=1; i<nums.size(); i++){
            if(nums[i] > maxi.first){
                maxi = make_pair(nums[i], i);
            }
        }

        TreeNode* root = new TreeNode(maxi.first);

        root->left =  buildTree(nums, 0, maxi.second-1);
        root->right = buildTree(nums, maxi.second+1, nums.size()-1);

        return root;
    }
};