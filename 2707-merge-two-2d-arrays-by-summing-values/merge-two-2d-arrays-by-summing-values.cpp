class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>ans;
        unordered_map<int,int>mp;
        for(auto ele : nums1){
            mp.insert({ele[0],ele[1]});
        }
        for(auto ele : nums2){
            if(mp.count(ele[0])){
                mp[ele[0]]+=ele[1];
            }
            else ans.push_back({ele[0],ele[1]});
        }
        for(auto it : mp){
            ans.push_back({it.first,it.second});
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};