class Solution {
public:
    int helper(TreeNode* root,long long tgtSum){
        if(!root) return 0;
        int cnt=0;
        if(root->val==tgtSum) cnt++;
        cnt+=helper(root->left,tgtSum-root->val);
        cnt+=helper(root->right,tgtSum-root->val);
        return cnt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return helper(root,targetSum) + pathSum(root->left,targetSum)
        +pathSum(root->right,targetSum); 
    }
};