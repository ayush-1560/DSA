class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches=0;
        long long  maxReachable = 0;
        int i=0;
        while(maxReachable < n){
            if(i<nums.size() && nums[i]<=maxReachable+1){
                maxReachable+=nums[i];
                i++;
            }
            else {
                maxReachable+=maxReachable+1;
                patches++;
            }
        }
        return patches;
    }
};