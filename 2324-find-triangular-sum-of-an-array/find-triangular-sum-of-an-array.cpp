class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while(n>1){
            vector<int>newNums;
            for(int i=0;i<nums.size()-1;i++){
            newNums.push_back((nums[i]+nums[i+1])%10);
            }
            nums=newNums;
            n--;
        }
        return nums[0];
    }
};