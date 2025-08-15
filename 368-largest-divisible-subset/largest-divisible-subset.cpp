class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>prev_idx(n,-1);
        int lastIdx = 0;
        int maxLen = 1;
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i] = dp[j]+1;
                        prev_idx[i]=j;
                    }
                    if(dp[i]>maxLen){
                        maxLen = dp[i];
                        lastIdx=i;
                    }
                }
            }
            
        }
        vector<int>ans;
        while(lastIdx!=-1){
            ans.push_back(nums[lastIdx]);
            lastIdx = prev_idx[lastIdx];
        }
        return ans;
    }
};