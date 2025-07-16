class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int len1=0,len2=0,len3=1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) len1++;
            else len2++;
        }
        int parity = nums[0]%2;
        for(int i=1;i<n;i++){
            int currParity = nums[i]%2;
            if(currParity!=parity){
                len3++;
                parity=currParity;
            }
        }
        return max({len1,len2,len3});
    }
};