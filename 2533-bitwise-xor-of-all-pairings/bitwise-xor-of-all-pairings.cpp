class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;
        if(n%2!=0) for(auto ele : nums2) ans = ans^ele;
        if(m%2!=0) for(auto ele : nums1) ans = ans^ele;
        return ans;
    }
};