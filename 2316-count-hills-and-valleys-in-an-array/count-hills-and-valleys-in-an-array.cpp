class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=1;
        int cnt=0;
        while(j+1<n){
            if((nums[j]>nums[i] && nums[j]>nums[j+1])
            || (nums[j]<nums[i] && nums[j]<nums[j+1])){
                cnt++;
                i=j;
            }
            j++;
        }
        return cnt;
    }
};