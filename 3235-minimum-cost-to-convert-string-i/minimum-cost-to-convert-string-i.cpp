class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>adj(26,vector<long long>(26,INT_MAX));
        for(int i=0;i<original.size();i++){
            adj[original[i]-'a'][changed[i]-'a']=min(adj[original[i]-'a'][changed[i]-'a'],(long long)cost[i]);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        long long minCost=0;
        for(int i=0;i<source.length();i++){
            if(source[i]==target[i]) continue;
            if(adj[source[i]-'a'][target[i]-'a']==INT_MAX) return -1;
            minCost+=adj[source[i]-'a'][target[i]-'a'];
        }
        return minCost;
    }
};