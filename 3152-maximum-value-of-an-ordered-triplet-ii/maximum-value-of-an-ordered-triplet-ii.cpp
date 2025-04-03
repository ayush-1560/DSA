class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftMax(n);
        vector<int>rightMax(n);
        long long ans=0;
        leftMax[0]=0;
        rightMax[n-1]=0;
        for(int i=1;i<n;i++){
            leftMax[i]=max(leftMax[i-1],nums[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],nums[i+1]);
        }
        for(int i=1;i<n-1;i++){
            ans=max(ans,(long long)(leftMax[i]-nums[i])*rightMax[i]);
        }
        return ans;
    }
};