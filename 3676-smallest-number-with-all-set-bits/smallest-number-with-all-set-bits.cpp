class Solution {
public:
    bool isValid(int n){
        return (n & (n + 1)) == 0;
    }
    int smallestNumber(int n) {
      for(int i=n;i<=pow(2,1000);i++){
        if(isValid(i)) return i;
      }
      return n+1;
    }
};