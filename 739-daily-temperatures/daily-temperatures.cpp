class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>nge(n,-1);
        stack<int>st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
                st.pop();
            }
            if(!st.empty()) nge[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            if(nge[i]==-1) nge[i]=0;
            else nge[i] = nge[i]-i;
        }
        return nge;
    }
};