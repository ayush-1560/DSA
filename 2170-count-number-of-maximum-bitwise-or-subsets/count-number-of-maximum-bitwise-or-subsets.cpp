class Solution {
public:
    vector<vector<int>>subs;
    void fill(int idx,vector<int>& nums,vector<int>&temp){
        if(idx==nums.size()) {
            subs.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        fill(idx+1,nums,temp);
        temp.pop_back();
        fill(idx+1,nums,temp);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        fill(0,nums,temp);
        int cnt=0;
        int maxOr=0;
        for(auto v : subs){
            int curror=0;
            for(auto ele : v) curror|=ele;
            maxOr=max(maxOr,curror);
        }
        for(auto v : subs){
            int curror=0;
            for(auto ele : v) curror|=ele;
            if(curror==maxOr) cnt++;
        }
        return cnt;
    }
};