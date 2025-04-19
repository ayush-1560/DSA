class Solution {
public:
    int totalNodes(TreeNode* root){
        if(!root) return 0;
        return 1 + totalNodes(root->left) + totalNodes(root->right); 
    }
    bool dfs(TreeNode* root, int idx,int nodes){
        if(!root) return true;
        if(idx > nodes) return false;
        return dfs(root->left,2*idx,nodes) && dfs(root->right,2*idx+1,nodes);
    }
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        int idx = 1;
        int nodes = totalNodes(root);
        return dfs(root,idx,nodes);
    }
};