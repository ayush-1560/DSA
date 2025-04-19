class Solution {
public:
    int depth(TreeNode* root){
        if(!root) return 0;
        return 1 + max(depth(root->left),depth(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(depth(root->left)-depth(root->right))>=2) return false;
        if(!isBalanced(root->left)) return false;
        if(!isBalanced(root->right)) return false;
        return true;
    }
};