class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int j=0;
        for(int i=0;i<n;i++){
                if(i+1<n && nums[i]==nums[i+1] && nums[i]!=0){
                    nums[i]*=2;
                    nums[i+1]=0;
                }
                if(nums[i]!=0){
                    if(i!=j){
                        swap(nums[i],nums[j]);
                    }
                    j++;
                }
        }
        return nums;
    }
};