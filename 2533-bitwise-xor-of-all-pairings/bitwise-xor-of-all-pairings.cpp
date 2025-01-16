class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int,long>mp;
        for(auto ele : nums1) mp[ele]+=m;
        for(auto ele : nums2) mp[ele]+=n;
        int ans=0;
        for(auto it : mp) if(it.second%2) ans^=it.first;
        return ans;
    }
};