class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>adj;
        vector<int>inDegree(numCourses,0);
        for(auto ele : prerequisites){
            adj[ele[0]].push_back(ele[1]);
            inDegree[ele[1]]++;
        }
        queue<int>q;
        for(int i=0;i<inDegree.size();i++){
            if(!inDegree[i]) q.push(i);
        }
        unordered_map<int,unordered_set<int>>mp;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                mp[it].insert(node);
                for(auto prereq : mp[node]){
                    mp[it].insert(prereq);
                }
                inDegree[it]--;
                if(inDegree[it]==0) q.push(it);
            }
        }
        int n = queries.size();
        vector<bool>ans(n,false);
        int i =0;
        for(auto query : queries){
            ans[i] = mp[query[1]].contains(query[0]);
            i++;
        }
        return ans;
    }
};