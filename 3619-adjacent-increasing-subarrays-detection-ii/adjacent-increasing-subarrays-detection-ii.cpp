class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int prevRun=0, currRun=1;
        int k = 0;
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]){
                currRun++;
                k = max(k,currRun/2);
            }
            else{
                prevRun=currRun;
                currRun=1;
            }
            k = max(k,min(prevRun,currRun));
        }
        return k;
    }
};