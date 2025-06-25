class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        vector<vector<int>>ans;
        while(!q.empty()){
            auto node = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            mp[col][row].insert(node->val);
            if(node->left){
                q.push({node->left,{row+1,col-1}});
            }
            if(node->right){
                q.push({node->right,{row+1,col+1}});
            }
        }
        for(auto it : mp){
            vector<int>v;
            for(auto p : it.second){
                v.insert(v.end(),p.second.begin(),p.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};