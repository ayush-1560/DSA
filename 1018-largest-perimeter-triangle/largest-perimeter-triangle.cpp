class Solution {
public:
    bool check(int a, int b, int c){
        return (a+b>c && b+c>a && a+c>b);
    }
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<>());
        int ans=0;
        for(int i=0;i<nums.size()-2;i++){
            if(check(nums[i],nums[i+1],nums[i+2])){
                ans = max(ans,nums[i]+nums[i+1]+nums[i+2]);
            }
        }
        return ans;
    }
};