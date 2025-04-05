
class Solution {
public:
    vector<vector<int>>ans;
    void solve(TreeNode* root,int s, int target,vector<int>&v){
        if(!root) return;
        v.push_back(root->val);
        s+=root->val;
        if(!root->left && !root->right){
            if(s==target) ans.push_back(v);
        }
        else{
            solve(root->left,s,target,v);
            solve(root->right,s,target,v);
        }
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>v;
        solve(root,0,targetSum,v);
        return ans;
    }
};