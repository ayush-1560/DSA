class Solution {
public:
    int ops(vector<int>&nums){
        int ops=0;
        vector<int>ans(nums.begin(),nums.end());
        sort(ans.begin(),ans.end());
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]=i;
        for(int i=0;i<nums.size();i++){
            if(ans[i]==nums[i]) continue;
            int currIdx = mp[ans[i]];
            mp[nums[i]]=currIdx;
            swap(nums[currIdx],nums[i]);
            ops++;
        }
        return ops;
    }
    int minimumOperations(TreeNode* root) {
        int steps=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>v;
            while(n--){
                auto node = q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            steps+=ops(v);
        }
        return steps;
    }
};