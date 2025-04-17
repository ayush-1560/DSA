class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>st;
    void solve(int idx,vector<int>& nums,vector<int>&temp){
        if(idx>=nums.size()){
            if(temp.size()>=2) st.insert(temp);
            return;
        }
        if(temp.empty() || temp.back()<=nums[idx]){
            temp.push_back(nums[idx]);
            solve(idx+1,nums,temp);
            temp.pop_back();
        }
        solve(idx+1,nums,temp);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>temp;
        solve(0,nums,temp);
        for(auto vec : st) ans.push_back(vec);
        return ans;
    }
};