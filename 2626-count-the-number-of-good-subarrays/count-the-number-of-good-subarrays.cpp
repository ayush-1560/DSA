class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0,r=0; long long cnt=0,ans=0;
        unordered_map<int,int>mp;
        while(r<n){
            cnt+=mp[nums[r]];
            mp[nums[r]]++;
            while(l<r && cnt>=k){
                ans+=n-r;
                mp[nums[l]]--;
                cnt-=mp[nums[l]];
                l++;
            }
            r++;
        }
        return ans;
    }
};