class Solution {
public:
    int solve(vector<int>& nums,int idx,int XOR){
        if(idx==nums.size()) return XOR;
        int include = solve(nums,idx+1,nums[idx]^XOR);
        int exclude = solve(nums,idx+1,XOR);
        return include + exclude;
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(nums,0,0);
    }
};