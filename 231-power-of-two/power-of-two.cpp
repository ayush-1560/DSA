class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
        if(n!=1 && n%2!=0) return false;
        while(n>0){
            if(n!=1 && n%2!=0) return false;
            if(n==1) return true;
            n/=2;
        }
        return false;
    }
};