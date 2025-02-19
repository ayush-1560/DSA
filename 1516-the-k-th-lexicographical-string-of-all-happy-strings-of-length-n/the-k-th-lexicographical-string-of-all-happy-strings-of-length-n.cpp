class Solution {
public:
    void solve(int n,string temp,vector<string>&ans){
        if(temp.size()==n){
            ans.push_back(temp);
            return ;
        }
        for(char ch='a';ch<='c';ch++){
            if( !temp.empty() && temp.back()==ch) continue;
            temp.push_back(ch);
            solve(n,temp,ans);
            temp.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<string>ans;
        solve(n,"",ans);
        if(ans.size()<k) return "";
        return ans[k-1];
    }
};