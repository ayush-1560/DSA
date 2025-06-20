class Solution {
public:
    void f(TreeNode* root,vector<int>&v){
        if(!root) return;
        if(!root->left && !root->right){
            v.push_back(root->val);
            return;
        }
        f(root->left,v);
        f(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1;
        vector<int>v2;
        f(root1,v1);
        f(root2,v2);
        return v1==v2;
    }
};