class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       unordered_set<int>st;
       int n = nums.size();
       int i=0,j=0;
       int maxSum=0,currSum=0;
       while(j<n){
            while(!st.empty() && st.count(nums[j])){
                currSum-=nums[i];
                st.erase(nums[i]);
                i++;
            }
            st.insert(nums[j]);
            currSum+=nums[j];
            maxSum=max(maxSum,currSum);
            j++;
       }
       return maxSum; 
    }
};