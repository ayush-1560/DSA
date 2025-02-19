class Solution {
public:
    void solve(int n,int i,string temp,vector<string>&ans){
        if(i>=n){
            ans.push_back(temp);
            return ;
        }
        for(char ch='a';ch<='c';ch++){
            if(i==0 || temp[i-1]!=ch){
                solve(n,i+1,temp+ch,ans);
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string>ans;
        solve(n,0,"",ans);
        if(ans.size()<k) return "";
        return ans[k-1];
    }
};