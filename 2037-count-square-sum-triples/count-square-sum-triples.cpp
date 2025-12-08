class Solution {
public:
    bool isValid(int a, int b, int c){
        return a*a + b*b == c*c;
    }
    int countTriples(int n) {
        int cnt=0;
            for(int a=1;a<=n;a++){
                for(int b=1;b<=n;b++){
                    for(int c=1;c<=n;c++){
                        if(isValid(a,b,c)) cnt++;
                    }
                }
            }
        return cnt;
    }
};