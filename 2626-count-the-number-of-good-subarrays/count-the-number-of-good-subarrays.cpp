class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        long long count = 0;
        int i=0,j=0,pairs=0;
        while(j<n){
            pairs+=mp[nums[j]];
            mp[nums[j]]++;
            while(pairs>=k){
                count+=(n-j);
                mp[nums[i]]--;
                pairs-=mp[nums[i]];
                i++;
            }
            j++;
        }
        return count;
    }
};