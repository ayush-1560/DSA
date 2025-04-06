class Solution {
public:
    vector<vector<int>>ans;
    void solve(int idx,vector<int>& candidates,int sum, int target,vector<int>&v){
        if(idx>=candidates.size()){
            if(sum==target){
                ans.push_back(v);
            }
            return;
        }
        if(sum+candidates[idx]<=target){ // stay on same idx till sum found
            v.push_back(candidates[idx]);
            solve(idx,candidates,sum+candidates[idx],target,v);
            v.pop_back();
        }
        solve(idx+1,candidates,sum,target,v);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>v;
        solve(0,candidates,0,target,v);
        return ans;
    }
};