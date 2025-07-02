
class Solution {
public:
    int inorder(TreeNode* root,int low, int high,int& sum){
        if(!root) return 0 ;
        if(root->val >=low && root->val<=high){
            return root->val + inorder(root->left,low,high,sum)
            +inorder(root->right,low,high,sum);
        }
        else if(root->val < low) return inorder(root->right,low,high,sum);
        else if(root->val > high) return inorder(root->left,low,high,sum);
        return sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        return inorder(root,low,high,sum);
    }
};