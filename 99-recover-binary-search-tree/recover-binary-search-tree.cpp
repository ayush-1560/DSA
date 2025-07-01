class Solution {
public:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(prev && root->val < prev->val){
            if(!first){
                first = prev;
                middle = root;
            }
            else last = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = prev = middle = last = NULL;
        inorder(root);
        if(first && last) swap(first->val,last->val);
        else if(first && middle) swap(first->val,middle->val);
    }
};