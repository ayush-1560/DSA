class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool>vis(n+1,false);
        for(int i=0;i<n;i++) vis[nums[i]]=true;
        vector<int>ans;
        for(int i =1 ;i<=n;i++) {
            if(!vis[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};