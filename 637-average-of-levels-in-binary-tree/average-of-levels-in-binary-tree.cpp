class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            double avg=0.0;
            int n = q.size();
            for(int i=0;i<n;i++){
                auto node = q.front();
                q.pop();
                avg+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            avg/=n;
            ans.push_back(avg);
        }
        return ans;
    }
};