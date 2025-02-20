class Solution {
public:
    void solve(int i,int n,string temp,vector<string>&ans){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        for(char ch='0';ch<='1';ch++){
            solve(i+1,n,temp+ch,ans);
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        string temp="";
        vector<string>ans;
        solve(0,nums.size(),temp,ans);
        unordered_set<string>st(nums.begin(),nums.end());
        for(auto ele : ans) {
            if(!st.count(ele)) return ele;
        }
        return "";
    }
};