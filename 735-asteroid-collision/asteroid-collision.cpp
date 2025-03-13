class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int>ans;
        stack<int>st;
        for(auto& ele : asteroids){
            while(!st.empty() && ele<0 && st.top()>0){
                int sum = ele + st.top();
                if(sum<0) st.pop();
                else if(sum>0) ele=0;
                else {
                    st.pop();
                    ele=0;
                }
            }
            if(ele!=0) st.push(ele);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};