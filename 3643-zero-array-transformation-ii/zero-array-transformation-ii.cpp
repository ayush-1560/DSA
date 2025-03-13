class Solution {
public:
    bool isZero(vector<int>& nums){
        for(auto ele : nums) if(ele!=0) return false;
        return  true;
    }
    bool check(vector<int>& nums, vector<vector<int>>& queries,int k){
        vector<int>diff(nums.size(),0);
        for(int i=0;i<=k;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];
            diff[l]+=x;
            if(r+1<nums.size()){
                diff[r+1]-=x;
            }
        }
        int cumSum=0;
        for(int i=0;i<nums.size();i++){
            cumSum+=diff[i];
            diff[i]=cumSum;
            if(nums[i]-diff[i]>0) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int Q= queries.size();
        if(isZero(nums)) return 0;
        int l=0,r=Q-1,ans=-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(check(nums,queries,mid)==true){
                ans=mid+1;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};