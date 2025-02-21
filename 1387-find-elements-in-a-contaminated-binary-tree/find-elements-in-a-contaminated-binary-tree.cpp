class FindElements {
public:
    TreeNode * newRoot;
    TreeNode* recover(TreeNode* root,int val){
        if(!root) return NULL;
        TreeNode* newNode = new TreeNode(val);
        newNode->left = recover(root->left,2*val+1);
        newNode->right= recover(root->right,2*val+2);
        return newNode;
    }
    bool findValue(TreeNode* root,int target){
        if(!root) return false;
        if(root->val==target) return true;
        return findValue(root->left,target) || findValue(root->right,target);
    }
    FindElements(TreeNode* root) {
        newRoot  = recover(root,0);
    }
    
    bool find(int target) {
        return findValue(newRoot,target);
    }
};
