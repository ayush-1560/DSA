class Solution {
public:
    int maxSum=INT_MIN;
    int solve(TreeNode* root){
        if(!root) return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        int sum1=l+r+root->val;
        int sum2=max(l,r)+root->val;
        int sum3=root->val;
        maxSum=max({maxSum,sum1,sum2,sum3});
        return max(sum2,sum3);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};