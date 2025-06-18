
class Solution {
public:
    TreeNode* nextRight = NULL;
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->left=NULL;
        root->right=nextRight;
        nextRight=root;
    }
};