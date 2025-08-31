class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int>nge;
        int m = nums2.size();
        vector<int>ans;
        stack<int>st;
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            if(!st.empty()) nge[nums2[i]] = st.top();
            else nge[nums2[i]] = -1;
            st.push(nums2[i]);
        }
        for(int num : nums1){
            ans.push_back(nge[num]);
        }
        return ans;
    }
};