class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++) v.push_back({i,nums[i]});
        sort(v.begin(),v.end(),[](pair<int,int>&p1,pair<int,int>&p2){
            return p1.second >p2.second;
        });
        sort(v.begin(),v.begin()+k);
        vector<int>ans;
        int i=0;
        while(k--){
            ans.push_back(v[i].second);
            i++;
        }
        return ans;
    }
};