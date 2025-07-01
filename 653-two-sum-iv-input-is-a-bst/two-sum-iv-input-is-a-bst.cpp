class BST1 {
public:
    stack<TreeNode*>st;
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    BST1(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* curr = st.top();
        st.pop();
        pushAll(curr->right);
        return curr->val;
    }
};
class BST2 {
public:
    stack<TreeNode*>st;
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            root=root->right;
        }
    }
    BST2(TreeNode* root) {
        pushAll(root);
    }
    
    int before() {
        TreeNode* curr = st.top();
        st.pop();
        pushAll(curr->left);
        return curr->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BST1 l (root);
        BST2 r (root);
        int i=l.next();
        int j=r.before();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.before();
        }
        return false;
    }
};