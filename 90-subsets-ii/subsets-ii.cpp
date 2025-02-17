class Solution {
public:
    void solve(vector<int>& nums,int idx,vector<int>&temp,
    vector<vector<int>>&ans){
        if(idx==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solve(nums,idx+1,temp,ans);
        temp.pop_back();
        int i=idx+1;
        while(i<nums.size() && nums[i]==nums[i-1]) i++;
        solve(nums,i,temp,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(nums,0,temp,ans);
        return ans;
    }
};