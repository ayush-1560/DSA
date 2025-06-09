class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        vector<int>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            ans[i]=(nums[i]*i)-(prefix[i]-nums[i]) + (prefix[n-1]-prefix[i]) -(nums[i]*(n-i-1));
        }
        return ans;
    }
};