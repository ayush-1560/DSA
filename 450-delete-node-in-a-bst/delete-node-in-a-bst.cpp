class Solution {
public:
    TreeNode* findIP(TreeNode* root){
        TreeNode* leftchild = root->left;
        while(leftchild->right){
            leftchild = leftchild->right;
        }
        return leftchild;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right,key);
        }
        else {
            if(!root->left && !root->right){
                return NULL;
            }
            else if(!root->left || !root->right){
                if(root->left) return root->left;
                else return root->right;
            }
            else{
                TreeNode* iop= findIP(root);
                root->val = iop->val;
                root->left= deleteNode(root->left,iop->val);
            }
        }
        return root;
    }
};