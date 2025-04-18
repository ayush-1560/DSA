class Solution {
public:
    int ans = 0;

    int height(TreeNode* root) {
        if (!root) return 0;

        int leftHt = height(root->left);
        int rightHt = height(root->right);

        ans = max(ans, leftHt + rightHt);
        return 1 + max(leftHt, rightHt);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }
};
