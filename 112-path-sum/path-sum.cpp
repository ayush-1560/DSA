class Solution {
public:
    bool solve(TreeNode* root,int s, int target){
        if(!root) return false;
        s+=root->val;
        if(!root->left && !root->right) return s==target;
        return solve(root->left,s,target) || solve(root->right,s,target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return solve(root,0,targetSum);
    }
};