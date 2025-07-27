class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int hills=0,valleys=0;
        set<pair<int,int>>st;
        for(int i=1;i<=n-2;i++){
            int leftIdx=-1;
            int rightIdx=n;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i] || nums[j]>nums[i]){
                    leftIdx=j;
                    break;
                }
            }
            for(int k=i+1;k<n;k++){
                if(nums[k]<nums[i] || nums[k]>nums[i]){
                    rightIdx=k;
                    break;
                }
            }
            if(leftIdx==-1 || rightIdx==n) continue;
            if(nums[i]>nums[leftIdx] && nums[i]>nums[rightIdx]){
                if(!st.count({leftIdx,rightIdx})){
                    hills++;
                    st.insert({leftIdx,rightIdx});
                }
            }
            else if(nums[i]<nums[leftIdx] && nums[i]<nums[rightIdx]){
                if(!st.count({leftIdx,rightIdx})){
                    valleys++;
                    st.insert({leftIdx,rightIdx});
                }
            }
        }
        return hills+valleys;
    }
};