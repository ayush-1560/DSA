class Solution {
public:
    bool hasCycle(unordered_map<int,vector<int>>&adj,int n){
        vector<int>indegree(n,0);
        for(int u=0;u<n;u++){
            for(int&v : adj[u]){
                indegree[v]++;
            }
        }
        int count=0;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;
            for(int&v : adj[u]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
        return (count!=n);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        for(auto course : prerequisites){
            adj[course[1]].push_back(course[0]);
        }
        return !hasCycle(adj,numCourses);
    }
};