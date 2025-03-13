class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>nsl(n,-1);
        vector<int>nsr(n,n);
        long long ans=0;
        int MOD = 1e9+7;
        nsl[0]=-1;
        nsr[n-1]=n;
        stack<int>st;
        stack<int>st2;
        st2.push(n-1);
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()) nsl[i]=st.top();
            st.push(i);
        }
        for(int i=n-2;i>=0;i--){
            while(!st2.empty() && arr[st2.top()]>arr[i]){
                st2.pop();
            }
            if(!st2.empty()) nsr[i]=st2.top();
            st2.push(i);
        }
        for(int i=0;i<n;i++){
            int leftVal = i-nsl[i];
            int rightVal = nsr[i]-i;
            ans=(ans+(long long)arr[i]*leftVal*rightVal)%MOD;
        }
        return ans;
    }
};