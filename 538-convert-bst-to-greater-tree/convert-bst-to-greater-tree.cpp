class Solution {
public:
    int sum=0;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->right);
        root->val = root->val + sum;
        sum = root->val;
        inorder(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        inorder(root);
        return root;
    }
};