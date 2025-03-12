class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int ans=0;
        colors.push_back(colors[0]);
        colors.push_back(colors[1]);
        int l=0,r=1;
        while(r<n+2){
            if(colors[r]==colors[r-1]){
                l=r;
            }
            if((r-l+1)==3){
                ans++;
                l++;
            }
            r++;
        }
        return ans;
    }
};