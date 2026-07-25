class Solution {
vector<int>findValues(int n){
    int max = -1, smax = -1;
    while(n>0){
        int d = n%10;
        if(d>max){
            smax = max;
            max = d;
        }
        else if(d>smax) smax = d;
        n/=10;
    }
    return {max,smax};
}
public:
    int maxProduct(int n) {
        vector<int>values = findValues(n);
        return values[0]*values[1];
    }
};