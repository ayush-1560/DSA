class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n>0){
                auto node =q.front();
                q.pop();
                if(n==1) ans.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                n--;
            }
        }
        return ans;
    }
};