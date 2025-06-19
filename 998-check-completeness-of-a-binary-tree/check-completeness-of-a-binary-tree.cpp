class Solution {
public:
    int count(TreeNode* root){
        if(!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }
    bool dfs(TreeNode* root,int i,int totalNodes){
        if(!root) return true;
        if(i>totalNodes) return false;
        return dfs(root->left,2*i,totalNodes) &&
        dfs(root->right,2*i+1,totalNodes);
    }
    bool isCompleteTree(TreeNode* root) {
       int totalNodes=count(root);
       int i=1;
       return dfs(root,i,totalNodes); 
    }
};