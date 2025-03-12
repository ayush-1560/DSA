class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int l=0,r=1;
        int temp=0;
        int ans=0;
        while(temp!=k-1){
            colors.push_back(colors[temp]);
            temp++;
        }
        int N= n+k-1;
        while(r<N){
            if(colors[r]==colors[r-1]){
                l=r;
            }
            if((r-l+1)==k){
                ans++;
                l++;
            }
            r++;
        }
        return ans;
    }
};