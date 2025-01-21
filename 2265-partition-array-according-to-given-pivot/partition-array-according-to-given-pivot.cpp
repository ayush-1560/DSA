class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<pair<int,int>>smaller;
        vector<pair<int,int>>equal;
        vector<pair<int,int>>larger;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot) smaller.push_back({i,nums[i]});
            else if(nums[i]==pivot) equal.push_back({i,nums[i]});
            else larger.push_back({i,nums[i]});
        }
        int idx=0;

        for(auto ele : smaller) {
            nums[idx] = ele.second;
            idx++;
        }
        for(auto ele : equal) {
            nums[idx] = ele.second;
            idx++;
        }
        for(auto ele : larger) {
            nums[idx] = ele.second;
            idx++;
        }
        return nums;
    }
};