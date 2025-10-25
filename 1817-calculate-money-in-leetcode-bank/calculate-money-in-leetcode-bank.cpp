class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int iv = 1;
        while(n>0){
            int sv=iv;
            for(int i=1;i<=min(n,7);i++){
                ans+=sv;
                sv++;
            }
            n-=7;
            iv++;
        }
        return ans;
    }
};