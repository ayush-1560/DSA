class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = n;
        int i =1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                i++;
                continue;
            }
            int peak =0;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                ans+=peak;
                i++;
                if(i==n) return ans;
            }
            int dip=0;
            while(i<n && ratings[i-1]>ratings[i]){
                dip++;
                ans+=dip;
                i++;
            }
            ans-=min(dip,peak);
        }
        return ans;
    }
};