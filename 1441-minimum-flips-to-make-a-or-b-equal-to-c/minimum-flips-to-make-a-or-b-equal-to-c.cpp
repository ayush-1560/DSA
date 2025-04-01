class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        for(int i=0;i<32;i++){
            int bitA=(a>>i)&1;
            int bitB=(b>>i)&1;
            int bitC=(c>>i)&1;
            if(bitC==0){
                count+=bitA+bitB;
            }
            else {
                if(bitA==0 && bitB==0) count++;
            }
        }
        return count;
    }
};