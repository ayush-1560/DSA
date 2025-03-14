class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int maxC=0;
        long long sum=0;
        for(auto ele : candies) {
            maxC=max(maxC,ele);
            sum+=ele;
        }
        if(sum<k) return 0;
        int l=1,r=maxC;
        int ans=0;
        while(l<=r){
            int mid = l+(r-l)/2;
            long long cnt=0;
            for(int i=0;i<n;i++){
                cnt+=(candies[i]/mid);
            }
            if(cnt>=k){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};