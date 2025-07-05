class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int>nums(501,0);
        for(int ele : arr) nums[ele]++;
        int maxEle=-1;
        for(int i=1;i<=500;i++) {
            if(nums[i]==i) maxEle=max(maxEle,i);
        }
        return maxEle;
    }
};