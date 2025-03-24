class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int>st(arr.begin(),arr.end());
        int low = 1, high = arr.back();
        for(int i=low;i<=high;i++){
            if(!st.count(i)) k--;
            if(k==0) return i;
        }
        int ans = arr.back();
        while(k--){
            ans++;
        }
        return ans;
    }
};