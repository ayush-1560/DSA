class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;
        return 1 + max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int diaLeft = diameterOfBinaryTree(root->left);
        int diaRight= diameterOfBinaryTree(root->right);
        int currHeight = height(root->left) + height(root->right);
        return max({diaLeft,diaRight,currHeight});
    }
};