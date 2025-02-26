class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int sum=0;
        for(int num : nums){
            sum+=num;
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
        }
        sum=0;
        for(int num : nums){
            sum+=num;
            mini=min(mini,sum);
            if(sum>0) sum=0;
        }
        return max(maxi,abs(mini));
    }
};