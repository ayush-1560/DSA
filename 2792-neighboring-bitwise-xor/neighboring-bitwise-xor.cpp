class Solution {
public:
    bool findArray(vector<int>&original,vector<int>& derived,int start){
        int n = original.size();
        original[0]=start;
        for(int i=1;i<n;i++){
            original[i] = original[i-1] ^ derived[i-1];
        }
        return (original[0] ^ original[n-1]==derived[n-1]);
    }
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int>original(n);
        bool app1 = findArray(original,derived,0);
        bool app2 = findArray(original,derived,0);
        return (app1 || app2);
    }
};