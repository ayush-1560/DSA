class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for(int num : nums) if(num<k) return -1;
        unordered_set<int>st(nums.begin(),nums.end());
        int cnt=0;
        for(int ele : st) if(ele>k) cnt++;
        return cnt;
    }
};