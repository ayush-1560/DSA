class Solution {
public:
    int countTriples(int n) {
        int cnt=0;
        for(int a=1;a<=n;a++){
            for(int b=a+1;b<=n;b++){
                int sq = (a*a) + (b*b);
                int x = sqrt(sq);
                if(x*x==sq && x<=n) cnt+=2;
            }
        }
        return cnt;
    }
};