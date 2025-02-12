class Solution {
public:
    int sumD(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for(auto& ele : nums){
            int sum=sumD(ele);
            mp[sum].push_back(ele);
        }
        for(auto& it : mp) sort(it.second.rbegin(),it.second.rend());
        int maxSum=INT_MIN;
        for(auto& it : mp){
            if(it.second.size()>=2){
                maxSum=max(maxSum,(it.second[0]+it.second[1]));
            }
        }
        return maxSum==INT_MIN ? -1 : maxSum;
    }
};