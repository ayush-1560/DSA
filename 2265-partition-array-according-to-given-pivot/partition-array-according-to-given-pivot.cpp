class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>ans(n);
        int idx=0;
        for(int i =0;i<n;i++){
            if(nums[i]<pivot){
                ans[idx] =nums[i];
                idx++;
            }
        }
        for(int i =0;i<n;i++){
            if(nums[i]==pivot){
                ans[idx] =nums[i];
                idx++;
            }
        }
        for(int i =0;i<n;i++){
            if(nums[i]>pivot){
                ans[idx] =nums[i];
                idx++;
            }
        }
        return ans;
    }
};