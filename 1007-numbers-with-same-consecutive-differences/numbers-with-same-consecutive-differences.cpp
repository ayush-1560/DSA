class Solution {
public:
    vector<int>ans;
    void solve(int n , int k,int num,int length){
        if(length==n){
            ans.push_back(num);
            return;
        }
        int lastdigit = num%10;
        if(lastdigit+k<=9){
            solve(n,k,num*10 + (lastdigit+k),length+1);
        }
        if(k!=0 && lastdigit-k>=0){
            solve(n,k,num*10 + (lastdigit-k),length+1);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++){
            solve(n,k,i,1);
        }
        return ans;
    }
};