class Solution {
public:
    typedef long long ll;
    ll findCost(vector<int>& nums, vector<int>& cost,int mid){
        ll ans =0;
        for(int i=0;i<nums.size();i++){
            ans+=(ll)abs(nums[i]-mid)*cost[i];
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans = INT_MAX;
        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid = low + (high-low)/2;
            ll cost1= findCost(nums,cost,mid);
            ll cost2= findCost(nums,cost,mid+1);
            ans = min(cost1,cost2);
            if(cost2>cost1){
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans == INT_MAX ?  0 :  ans;
    }
};