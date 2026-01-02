class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0,element=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) {
                cnt++;
            }
            else cnt=0;
            if((cnt+1)==nums.size()/2) element = nums[i];
        }
        return element;
    }
};