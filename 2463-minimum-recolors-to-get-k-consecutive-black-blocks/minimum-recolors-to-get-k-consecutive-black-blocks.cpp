class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=INT_MAX;
        int blackCount=0,whiteCount=0;
        int l=0,r=0;
        while(r<blocks.length()){
            blocks[r]=='W' ? whiteCount++ : blackCount++;
            if((r-l+1)==k){
                ans=min(ans,whiteCount);
                if(blocks[l]=='W') whiteCount--;
                else blackCount--;
                l++;
            }
            r++;
        }
        return ans;
    }
};