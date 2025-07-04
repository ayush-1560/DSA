class Solution {
public:
    vector<TreeNode*> solve(int start, int end){
        if(start > end) return {NULL};
        if(start == end){
            TreeNode* root = new TreeNode(start);
            return {root};
        }
        vector<TreeNode*>ans;
        for(int i=start;i<=end;i++){
            auto left_BST = solve(start,i-1);
            auto right_BST = solve(i+1,end);
            for(auto leftRoot : left_BST){
                for(auto rightRoot : right_BST){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};