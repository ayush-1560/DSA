class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        for(auto preq : prerequisites){
            adj[preq[1]].push_back(preq[0]);
            indegree[preq[0]]++;
        }
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        int courseCnt=0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            courseCnt++;
            for(int v : adj[u]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
        return courseCnt==numCourses;
    }
};