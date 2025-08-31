class Solution {
public:
    void fillNse(vector<int>& heights,vector<int>&nse){
        int n = heights.size();
        stack<int>st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()) nse[i]=st.top();
            st.push(i);
        }
    }
    void fillPse(vector<int>& heights,vector<int>&pse){
        int n = heights.size();
        stack<int>st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()) pse[i]=st.top();
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea=0;
        vector<int>nse(n,n),pse(n,-1);
        fillNse(heights,nse);
        fillPse(heights,pse);
        for(int i=0;i<n;i++){
            maxArea = max(maxArea,heights[i]*(nse[i]-pse[i]-1));
        }
        return maxArea;
    }
};