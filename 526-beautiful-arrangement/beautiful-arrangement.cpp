class Solution {
public:
    int count=0;
    void solve(int idx,vector<int>&nums){
        if(idx==nums.size()){
            count++;
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            if(nums[idx]%(idx+1)==0 || (idx+1)%nums[idx]==0)
            solve(idx+1,nums);
            swap(nums[i],nums[idx]);
        }
    }
    int countArrangement(int n) {
        vector<int>nums(n,0);
        for(int i=0;i<n;i++) nums[i]=i+1;
        solve(0,nums);
        return count;
    }
};