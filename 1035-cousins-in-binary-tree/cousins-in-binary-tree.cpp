class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*,pair<TreeNode*,int>>>q;
        TreeNode* parent_x=NULL;
        int x_depth=0;
        TreeNode* parent_y=NULL;
        int y_depth=0;
        q.push({root,{NULL,0}});
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto node = q.front().first;
                auto parent = q.front().second.first;
                int depth = q.front().second.second;
                q.pop();
                if(node->val==x){
                    parent_x=parent;
                    x_depth=depth;
                }
                if(node->val==y){
                    parent_y=parent;
                    y_depth=depth;
                }
                if(node->left){
                    q.push({node->left,{node,depth+1}});
                }
                if(node->right){
                    q.push({node->right,{node,depth+1}});
                }
            }
        }
        return parent_x!=parent_y && x_depth==y_depth;
    }
};