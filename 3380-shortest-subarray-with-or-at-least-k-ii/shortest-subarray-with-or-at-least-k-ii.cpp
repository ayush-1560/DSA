class Solution {
public:
    void update(int num ,vector<int>&v,int val){
        for(int i=0;i<32;i++){
            if((num>>i)&1){
                v[i]+=val;
            }
        }
    }
    int getDecimal(vector<int>&v){
        int num = 0;
        for(int i=0;i<32;i++){
            if(v[i]>0){
                num|=(1<<i);
            }
        }
        return num;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0,minLen=INT_MAX;
        vector<int>v(32,0);
        while(j<n){
            update(nums[j],v,1);
            while(i<=j && getDecimal(v)>=k){
                minLen = min(minLen,j-i+1);
                update(nums[i],v,-1);
                i++;
            }
            j++;
        }
        return minLen==INT_MAX ? -1 : minLen;
    }
};