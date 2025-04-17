class Solution {
public:
    void solve(int idx,vector<int>& nums, int k,unordered_map<int,int>&mp,int&count){
        if(idx>=nums.size()){
            count++;
            return;
        }
        solve(idx+1,nums,k,mp,count);
        if(!mp[nums[idx]-k] && !mp[nums[idx]+k]){
            mp[nums[idx]]++;
            solve(idx+1,nums,k,mp,count);
            mp[nums[idx]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int count =0;
        solve(0,nums,k,mp,count);
        return count-1;
    }
};