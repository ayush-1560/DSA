class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int newIdx= (i+k)%n;
            ans[newIdx] =nums[i];
        }
        for (int i = 0; i < n; i++) {
        nums[i] = ans[i]; 
    }
    }
    bool check(vector<int>& nums) {
       vector<int>arr=nums;
       sort(arr.begin(),arr.end());
       for(int i=0;i<nums.size();i++){
            rotate(nums,1);
            if(arr==nums) return true;
       }
       return false;
    }
};