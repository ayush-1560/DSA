class Solution {
public:
    bool isNegative(vector<int>& nums){
        for(int ele : nums) if(ele>=0) return false;
        return true;
    }
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        if(isNegative(nums)){
            return *max_element(nums.begin(),nums.end());
        }
        int maxSum=0;
        unordered_set<int>st;
        for(int num : nums) {
            if(!st.count(num) && num>=0){
                maxSum+=num;
                st.insert(num);
            }
        }
        return maxSum;
    }
};