class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count =0;
        int n = nums.size();
        int i=0,j=0;
        while(j<n){
            while(j<n && nums[j]!=0) j++;
            i=j;
            while(j<n && nums[j]==0){
                count+=j-i+1;
                j++;
            }
        }
        return count;
    }
};