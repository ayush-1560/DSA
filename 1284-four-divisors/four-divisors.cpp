class Solution {
public:
    bool isValid(int n){
        int cnt=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                cnt++;
                if(i!=n/i) cnt++;
            } 
        }
        return cnt==4;
    }
    int calcSum(int n){
        int sum=0;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0) {
                sum+=i;
                if(i!=n/i) sum+=(n/i);
            }
        }
        return sum;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(int num : nums){
            if(isValid(num)){
                sum+=calcSum(num);
            }
        }
        return sum;
    }
};