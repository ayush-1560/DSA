class FindElements {
public:
    unordered_set<int>st;
    void DFS(TreeNode* root, int x){
        if(!root) return;
        root->val =x;
        st.insert(x);
        DFS(root->left,2*x+1);
        DFS(root->right,2*x+2);
    }
    FindElements(TreeNode* root) {
        DFS(root,0);
    }
    
    bool find(int target) {
        return (st.count(target));
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */