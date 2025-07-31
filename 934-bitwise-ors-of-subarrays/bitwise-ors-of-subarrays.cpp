class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>ans,prev,curr;
        int n = arr.size();
        for(int i=0;i<n;i++){
            for(int x : prev){
                curr.insert(arr[i]|x);
                ans.insert(arr[i]|x);
            }
            curr.insert(arr[i]);
            ans.insert(arr[i]);
            prev = curr;
            curr.clear();
        }
        return ans.size();
    }
};