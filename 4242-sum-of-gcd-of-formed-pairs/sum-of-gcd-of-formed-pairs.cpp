class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixGCD(n);
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
            prefixGCD[i] = gcd(nums[i],mx);
        }
        sort(prefixGCD.begin(),prefixGCD.end());
        int i=0,j=n-1;
        long long gcdSum = 0;
        while(i<j){
            gcdSum+=gcd(prefixGCD[i],prefixGCD[j]);
            i++;
            j--;
        }

        return gcdSum;
    }
};