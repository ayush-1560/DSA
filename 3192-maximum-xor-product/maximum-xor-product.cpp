class Solution {
public:
    typedef long long ll;
    int maximumXorProduct(long long a, long long b, int n) {
        int M = 1e9+7;
        ll aXorX = 0 , bXorX =0 ;
        for(ll i=49;i>=n;i--){
            bool aset= ((a>>i) & 1 ) > 0;
            bool bset= ((b>>i) & 1 ) > 0;
            if(aset){
                aXorX^=(1ll << i);
            }
            if(bset){
                bXorX^=(1ll << i);
            }
        }
        for(ll i=n-1;i>=0;i--){
            bool aset= ((a>>i) & 1 ) > 0;
            bool bset= ((b>>i) & 1 ) > 0;
            if(aset==bset){
                 aXorX^=(1ll << i);
                 bXorX^=(1ll << i);
                 continue;
            }
            if(aXorX > bXorX){
                bXorX^=(1ll << i);
            }
            else {
                aXorX^=(1ll << i);
            }
        }
        aXorX=aXorX%M;
        bXorX=bXorX%M;
        return (aXorX*bXorX) % M;
    }
};