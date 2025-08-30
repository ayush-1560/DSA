class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefP=1,maxP=INT_MIN,suffP=1;
        for(int i=0;i<n;i++){
            if(prefP==0) prefP=1;
            if(suffP==0) suffP=1;
            prefP*=nums[i];
            suffP*=nums[n-i-1];
            maxP=max({maxP,prefP,suffP});
        }
        return maxP;
    }
};