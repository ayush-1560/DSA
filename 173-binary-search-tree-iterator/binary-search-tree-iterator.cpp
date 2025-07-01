class BSTIterator {
public:
    vector<int>ino;
    TreeNode* treeRoot;
    int idx=0;
    int curr;
    void fill(TreeNode* treeRoot){
        if(!treeRoot) return;
        fill(treeRoot->left);
        ino.push_back(treeRoot->val);
        fill(treeRoot->right);
    }
    BSTIterator(TreeNode* root) {
        treeRoot=root;
        fill(treeRoot);
    }
    
    int next() {
        curr=ino[idx];
        if(idx<ino.size()) idx++;
        return curr;
    }
    
    bool hasNext() {
        return idx<ino.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */