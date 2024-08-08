/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* root, TreeNode* target, vector<TreeNode*> &v){
       if(!root) return false;
       if(root == target) {
           v.push_back(root);
           return true;
        }

        bool left = helper(root->left, target, v);
        if(left){
            v.push_back(root);
            return true;
        }
        bool right = helper(root->right, target, v);
        if(right){
            v.push_back(root);
            return true;
        }

        return false;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> fp;
        vector<TreeNode*> fq;
        TreeNode* ans = NULL;

        bool a = helper(root, p, fp);
        bool b = helper(root, q, fq);

        reverse(fp.begin(), fp.end());
        reverse(fq.begin(), fq.end());

        for(int i=0; i<fq.size(); i++){
            cout<<fq[i]<<" ";
        }

        for(int i=0; i<fq.size(); i++){
            cout<<fq[i]<<" ";
        }

        if(fp.size()>=fq.size()){
            for(int i=0; i<fq.size(); i++){
                if(fp[i] == fq[i]) ans = fp[i];
            }
        }
        else{
           for(int i=0; i<fp.size(); i++){
                if(fq[i] == fp[i]) ans = fp[i];
            } 
        }

        return ans;
    }
};