class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int lastIdx=-1;
        if(nums[0]==1) lastIdx=0;
        int i=1;
        while(i<n){
            if(nums[i]==1){
                if( lastIdx!=-1 && i-lastIdx-1 < k) return false;
                else lastIdx=i;
            }
            i++;
        }
        return true;
    }
};