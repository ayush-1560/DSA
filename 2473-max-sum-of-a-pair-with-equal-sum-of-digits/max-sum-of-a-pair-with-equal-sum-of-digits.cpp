class Solution {
public:
    int sumD(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int mp[82]={0};
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int digitSum=sumD(nums[i]);
            if(mp[digitSum]>0){
               ans=max(ans,nums[i]+ mp[digitSum]); 
            }
            mp[digitSum] = max(mp[digitSum],nums[i]);
        }
        return ans;
    }
};