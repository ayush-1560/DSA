class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int leftHt = minDepth(root->left);
        int rightHt = minDepth(root->right);
        if(!leftHt) return 1 + rightHt;
        else if (!rightHt) return 1 + leftHt;
        else return 1 + min(leftHt,rightHt);
    }
};