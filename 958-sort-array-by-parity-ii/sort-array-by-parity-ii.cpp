class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int oddIdx=1;
        int evenIdx=0;
        int n = nums.size();
        while(evenIdx<n && oddIdx<n){
            if(nums[evenIdx]%2==0) evenIdx+=2;
            else if(nums[oddIdx]%2) oddIdx+=2;
            else swap(nums[evenIdx],nums[oddIdx]);
        }
        return nums;
    }
};