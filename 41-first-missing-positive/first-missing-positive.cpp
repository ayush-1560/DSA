class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int>vis(n+1,0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0 && nums[i]<=n){
                vis[nums[i]] =1;
            }
        }
        for(auto ele : vis) cout<<ele<<" ";
        for(int i=1;i<=n;i++){
            if(vis[i]==0) return i;
        }
        return n+1;
    }
};