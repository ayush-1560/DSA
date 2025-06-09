class Solution {
public:
    int convert(int n, int k){
        string temp="";
        while(n>0){
            temp+=to_string(n%k);
            n/=k;
        }
        reverse(temp.begin(),temp.end());
        return stoi(temp);
    }
    int sum(int num){
        int sum=0;
        while(num>0){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    int sumBase(int n, int k) {
        int num = convert(n,k);
        return sum(num);
    }
};