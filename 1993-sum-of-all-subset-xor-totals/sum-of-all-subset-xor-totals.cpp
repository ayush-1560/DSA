class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int OR=0;
        for(int num : nums) OR|=num;
        return OR<<=(n-1);
    }
};