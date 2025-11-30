class Solution {
public:
    int minSubarray(vector<int>& nums, int P) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums) sum = (sum+num)%P;
        int target = sum%P;
        if(target==0) return 0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int curr=0;
        int minLen = n;
        for(int j=0;j<n;j++){
            curr = (curr+nums[j])%P;
            if(mp.count((curr-target + P)%P)){
                minLen = min(minLen,j-mp[(curr-target + P)%P]);
            }
            mp[curr] = j;
        }
        return minLen==n ? -1 : minLen;
    }
};