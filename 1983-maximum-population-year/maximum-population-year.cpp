class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int>mp;
        int maxi=INT_MIN;
        int ans=logs[0][0];
        for(auto log : logs){
            mp[log[0]]++;
            mp[log[1]]--;
        }
        int sum=0;
        for(auto it : mp){
            sum+=it.second;
            if(sum>maxi){
                ans=it.first;
                maxi=sum;
            }
        }
        return ans;
    }
};