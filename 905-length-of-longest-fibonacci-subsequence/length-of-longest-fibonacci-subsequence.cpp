class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans=0;
        unordered_set<int>st(arr.begin(),arr.end());
        int n = arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int prev = arr[j];
                int currSum = arr[i] + arr[j];
                int len =2;
                while(st.count(currSum)){
                    int temp = currSum;
                    currSum+=prev;
                    prev=temp;
                    len++;
                    ans = max(ans,len);
                }
            }
        }
        return ans;
    }
};