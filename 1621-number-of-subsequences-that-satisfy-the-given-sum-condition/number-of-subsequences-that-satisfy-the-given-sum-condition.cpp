class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt =0;
        int mod=1e9+7;
        vector<int> pow(n + 1, 1);
        for (int i = 1; i <= n; i++) {
        pow[i] = (1LL * pow[i - 1] * 2) % mod;
        }
        sort(nums.begin(),nums.end());
        int l=0,r=n-1;
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                cnt=(cnt+pow[r-l])%mod;
                l++;
            }
            else r--;
        }
        return cnt;
    }
};