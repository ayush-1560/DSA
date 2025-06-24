class Solution {
public:
    string convert2K(long long num,int k){
        string str="";
        while(num>0){
            str+=to_string(num%k);
            num/=k;
        }
        return str;
    }
    bool isPal(string str){
        int i=0,j=str.length()-1;
        while(i<=j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    long long kMirror(int k, int n) {
        long long sum=0;
        int L=1;
        while(n>0){
            int half_length = (L+1)/2;
            long long minNum=pow(10,half_length-1);
            long long maxNum=pow(10,half_length)-1;
            for(int num=minNum;num<=maxNum;num++){
                string first_half=to_string(num);
                string second_half=to_string(num);
                reverse(second_half.begin(),second_half.end());
                string pal="";
                if(L%2==0){
                    pal=first_half+second_half;
                }
                else{
                    pal=first_half+second_half.substr(1);
                }
                long long pal_num=stoll(pal);
                string baseK=convert2K(pal_num,k);
                if(isPal(baseK)) {
                    sum+=pal_num;
                    n--;
                    if(n==0) break;
                }
            }
            L++;
        }
        return sum;
    }
};