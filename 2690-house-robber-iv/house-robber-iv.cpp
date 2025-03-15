class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n  = nums.size();
        int l = *min_element(nums.begin(),nums.end());
        int r = *max_element(nums.begin(),nums.end());
        int ans =r;
        while(l<=r){
            int mid = l+(r-l)/2;
            int houseCount=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=mid){
                    houseCount++;
                    i++;
                }
            }
            if(houseCount>=k){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};