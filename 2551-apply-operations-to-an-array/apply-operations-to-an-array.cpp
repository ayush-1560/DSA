class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-1;i++){
                if(nums[i]==nums[i+1]){
                    nums[i]*=2;
                    nums[i+1]=0;
                }
        }
        int zeroes =0;
        vector<int>ans;
        for(auto ele : nums){
            if(ele==0) zeroes++;
            else ans.push_back(ele);
        } 
        while(zeroes--) ans.push_back(0);
        return ans;
    }
};