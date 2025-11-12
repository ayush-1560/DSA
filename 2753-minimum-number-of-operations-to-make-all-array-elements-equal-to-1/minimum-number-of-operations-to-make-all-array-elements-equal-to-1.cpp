class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt1=0;
        for(int num : nums) if(num==1) cnt1++;
        if(cnt1>0) return n-cnt1;
        int ops=INT_MAX;
        for(int i=0;i<n-1;i++){
            int gcd = nums[i];
            for(int j=i+1;j<n;j++){
                gcd = __gcd(gcd,nums[j]);
                if(gcd==1) ops = min(ops,j-i);
            }
        }
        return ops==INT_MAX ? -1 : ops + (n-1);
    }
};