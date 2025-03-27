class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        if(n!=1 && n%4!=0) return false;
        while(n>0){
            if(n!=1 && n%4!=0) return false;
            if(n==1) return true;
            n/=4;
        }
        return false;
    }
};