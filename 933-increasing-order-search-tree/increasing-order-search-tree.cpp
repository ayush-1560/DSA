class Solution {
public:
    TreeNode* newRoot = new TreeNode(-1);
    TreeNode* newtemp=newRoot;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        newtemp->left = NULL;
        newtemp->right=new TreeNode(root->val);
        newtemp = newtemp->right;
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return newRoot->right;
    }
};