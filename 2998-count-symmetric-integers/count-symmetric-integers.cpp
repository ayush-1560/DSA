class Solution {
public:
    bool isSymmetric(int num){
        string str = to_string(num);
        int sum1=0,sum2=0;
        for(int i=0;i<str.length()/2;i++){
            sum1+=str[i]-'0';
        }
        for(int i=str.length()/2;i<str.length();i++){
            sum2+=str[i]-'0';
        }
        return sum1==sum2;
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int num = low;num<=high;num++){
            int len = log10(num)+1;
            if(len>=2 && len%2==0){
                if(isSymmetric(num)) cnt++;
            }
        }
        return cnt;
    }
};