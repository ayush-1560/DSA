class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        unordered_set<int>st;
        for(int i=n-1;i>=0;i--){
            if(isdigit(s[i])){
                for(int j=i-1;j>=0;j--){
                    if(!isdigit(s[j]) && !st.count(j)){
                        st.insert(j);
                        break;
                    }
                }
            }
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(!st.count(i) && !isdigit(s[i])) ans+=s[i];
        }
        return ans;
    }
};