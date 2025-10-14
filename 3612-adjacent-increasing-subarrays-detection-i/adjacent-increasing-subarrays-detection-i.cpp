class Solution {
public:
    bool check(vector<int>& nums,int i,int k){
        for(int t =i+1;t<i+k;t++){
            if(nums[t] <= nums[t-1]) return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i+2*k-1<n;i++){
            bool flag = false;
            int j = i;
            if(check(nums,j,k) && check(nums,j+k,k)) flag = true;
            if(flag) return true;
        }
        return false;
    }
};