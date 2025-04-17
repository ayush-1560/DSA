class Solution {
public:
    vector<string>ans;
    void solve(int n,int k,string temp){
        if(ans.size()==k) return;
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        unordered_set<char>st;
        for(char ch='a';ch<='c';ch++){
            if(temp.empty() || temp.back()!=ch){
                solve(n,k,temp+ch);
            }
        }
    }
    string getHappyString(int n, int k) {
        solve(n,k,"");
        if(k>ans.size()) return "";
        return ans[k-1];
    }
};