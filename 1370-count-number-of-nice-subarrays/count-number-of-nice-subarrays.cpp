class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0) count++;
            int rem = count-k;
            if(mp.find(rem)!=mp.end()){
                ans+=mp[rem];
            }
            mp[count]++;
        }
        return ans;
    }
};