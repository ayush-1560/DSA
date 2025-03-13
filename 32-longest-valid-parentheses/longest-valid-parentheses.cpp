class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int>st;
        int lastInvalid=-1;
        int maxLen=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else{
                if(!st.empty()){
                    st.pop();
                    if(st.empty()){
                        maxLen=max(maxLen,i-lastInvalid);
                    }
                    else maxLen = max(maxLen,i-st.top());
                }
                else lastInvalid = i;
            }
        }
        return maxLen;
    }
};