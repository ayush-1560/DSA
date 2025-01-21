class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int>ans(nums.size());
        int oddIdx=1;
        int evenIdx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2) {
                ans[oddIdx]=nums[i];
                oddIdx+=2;
            }
            else{
                ans[evenIdx]=nums[i];
                evenIdx+=2;
            }
        }
        return ans;
    }
};