
class Solution {
public:
    int minDiff=INT_MAX;
    int currNum;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(currNum!=root->val)minDiff=min(minDiff,(abs)(root->val-currNum));
        currNum=root->val;
        inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        currNum=root->val;
        inorder(root);
        return minDiff;
    }
};