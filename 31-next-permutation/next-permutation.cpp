class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int correctIdx=-1;
        for(int i=n-1;i>0;i--){
            if(nums[i-1] < nums[i]){
                correctIdx= i-1;
                break;
            }
        }
        if(correctIdx!=-1){
            int swapIdx=correctIdx;
            for(int i=n-1;i>=correctIdx+1;i--){
                if(nums[i] > nums[correctIdx]){
                    swapIdx = i;
                    break;
                }
            }
            swap(nums[correctIdx],nums[swapIdx]);
        }
        reverse(nums.begin() + correctIdx + 1, nums.end());
    }
};