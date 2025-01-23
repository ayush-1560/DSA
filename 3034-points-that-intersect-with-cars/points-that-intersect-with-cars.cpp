class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int maxi=INT_MIN;
        for(auto query : nums) maxi=max({maxi,query[0],query[1]});
        vector<bool>vis(maxi+1,false);
        for(auto query : nums)for(int i=query[0];i<=query[1];i++) vis[i]=true;
        int ans=0;
        for(auto ele : vis) if(ele) ans++;
        return ans;
    }
};