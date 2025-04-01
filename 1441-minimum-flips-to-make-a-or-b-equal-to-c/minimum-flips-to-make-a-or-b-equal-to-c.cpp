class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        while(a || b || c){
            if(c&1){
                if((a&1)==0 && (b&1)==0) count++;
            }
            else{
                count+=(a&1) + (b&1);
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return count;
    }
};