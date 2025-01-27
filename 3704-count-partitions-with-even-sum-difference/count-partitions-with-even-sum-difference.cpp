class Solution {
public:
    int countPartitions(vector<int>& nums) {
       int n = nums.size();
       int totalSum =0;
       for(auto it : nums) totalSum+=it;
       int currSum=0;
       int ans=0;
       for(auto ele : nums){
          currSum+=ele;
          totalSum-=ele;
          if(totalSum <=0) break;
          if(abs(currSum-totalSum)%2==0) ans++;
       }
       return ans;
    }
};