class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        unordered_map<int,vector<int>>adj;
        int n = routes.size();
        for(int i=0;i<n;i++){
            for(int route : routes[i]){
                adj[route].push_back(i);
            }
        }
        vector<bool>vis(501,false);
        queue<int>q;
        for(int ele : adj[source]) {
            q.push(ele);
            vis[ele]=true;
        }
        int busCount=1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int route = q.front();
                q.pop();
                for(auto stop : routes[route]){
                    if(stop == target) return busCount;
                    for(auto nextRoute : adj[stop]){
                        if(!vis[nextRoute]){
                            vis[nextRoute] = true;
                            q.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
};