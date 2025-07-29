class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        vector<int>setBitIdx(32,-1);
        for(int i=n-1;i>=0;i--){
            int endIdx=i;
            for(int j=0;j<31;j++){
                if(!(nums[i]&(1<<j))){
                    if(setBitIdx[j]!=-1){
                        endIdx = max(endIdx,setBitIdx[j]);
                    }
                }
                else{
                    setBitIdx[j]=i;
                }
            }
            ans[i] = endIdx-i+1;
        }
        return ans;
    }
};