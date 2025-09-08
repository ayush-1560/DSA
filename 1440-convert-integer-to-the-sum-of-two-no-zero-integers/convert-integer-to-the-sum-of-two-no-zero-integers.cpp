class Solution {
public:
    bool isValid(int n){
        if(n==0) return false;
        while(n>0){
            if(n%10==0) return false;
            n/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int>ans;
        for(int i=n;i>=1;i--){
            int num1 = i;
            int num2 = n-i;
            if(isValid(num1) && isValid(num2)) {
                ans.push_back(num1);
                ans.push_back(num2);
                break;
            }
        }
        return ans;
    }
};