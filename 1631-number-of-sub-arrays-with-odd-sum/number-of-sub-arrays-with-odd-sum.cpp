class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int count_even =1;
        int count_odd = 0;
        int preSum=0;
        int ans=0,MOD=1e9+7;
        for(auto ele : arr){
            preSum+=ele;
            if(preSum%2==0) {
                ans=(ans+count_odd)%MOD;
                count_even++;
            }
            else {
                ans=(ans+count_even)%MOD;
                count_odd++;
            }
        }
        return ans;
    }
};