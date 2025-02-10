class Solution {
public:
    int bs(int target_idx,int k,vector<int>& nums,vector<long>&pre){
        int target=nums[target_idx];
        int l=0,r=target_idx,ans=target_idx;
        while(l<=r){
            int mid = l + (r-l)/2;
            long count = (target_idx -mid +1);
            long windowSum = count*target;
            long currSum = pre[target_idx] - pre[mid] + nums[mid];
            int ops = windowSum-currSum;
            if(ops > k){
                l=mid+1;
            }
            else{
                ans=mid;
                r=mid-1;
            }
        }
        return (target_idx-ans+1);
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<long>pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,bs(i,k,nums,pre));
        }
        return ans;
    }
};