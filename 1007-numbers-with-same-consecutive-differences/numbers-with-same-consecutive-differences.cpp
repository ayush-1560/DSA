class Solution {
public:
    vector<int>ans;
    void solve(int n , int k,int num){
        int len = log10(num)+1;
        if(len==n){
            ans.push_back(num);
            return;
        }
        int lastdigit = num%10;
        if(lastdigit+k<=9){
            solve(n,k,num*10 + (lastdigit+k));
        }
        if(k!=0 && lastdigit-k>=0){
            solve(n,k,num*10 + (lastdigit-k));
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++){
            solve(n,k,i);
        }
        return ans;
    }
};