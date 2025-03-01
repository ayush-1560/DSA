class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int zeroes =0;
        for(int i=0;i<n-1;i++){
                if(nums[i]==nums[i+1]){
                    nums[i]*=2;
                    nums[i+1]=0;
                }
        }
        int i=0,j=0;
        while(i<n){
            if(nums[i]!=0){
                nums[j]=nums[i];
                j++;
            }
            i++;
        }
        while(j<n){
            nums[j]=0;
            j++;
        }
        return nums;
    }
};