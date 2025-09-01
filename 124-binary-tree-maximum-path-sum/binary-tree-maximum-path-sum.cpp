class Solution {
public:
    int maxSum;
    
    int dfs(TreeNode* root) {
        if (!root) return 0;
        
        // compute max gain from left and right
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        
        // max path sum passing through this node
        maxSum = max(maxSum, root->val + left + right);
        
        // return the best single path upwards
        return root->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        dfs(root);
        return maxSum;
    }
};