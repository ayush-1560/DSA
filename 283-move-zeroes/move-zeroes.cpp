class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=0;
        while(j<n){
            while(i<n && nums[i]!=0) i++;
            if( i<j && nums[j]!=0) swap(nums[i],nums[j]);
            j++;
        }
        
    }
};