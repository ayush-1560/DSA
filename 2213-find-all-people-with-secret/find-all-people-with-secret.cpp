class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int,vector<pair<int,int>>>mp;
        for(auto meeting : meetings){
            mp[meeting[2]].push_back({meeting[0],meeting[1]});
        }
        vector<bool>knowsSecret(n,false);
        knowsSecret[0]=true;
        knowsSecret[firstPerson] = true;
        for(auto it : mp){
            vector<pair<int,int>> meets = it.second;
            unordered_map<int,vector<int>>adj;
            unordered_set<int>st;
            queue<int>q;
            for(auto&[person1,person2] : meets){
                adj[person1].push_back(person2);
                adj[person2].push_back(person1);
                if(knowsSecret[person1] && !st.count(person1)){
                    q.push(person1);
                    st.insert(person1);
                }
                if(knowsSecret[person2] && !st.count(person2)){
                    q.push(person2);
                    st.insert(person2);
                }
            }
            while(!q.empty()){
                int person = q.front();
                q.pop();
                knowsSecret[person]=true;
                for(int ngbr : adj[person]){
                    if(!knowsSecret[ngbr]){
                        knowsSecret[ngbr] = true;
                        q.push(ngbr);
                    }
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(knowsSecret[i]) ans.push_back(i);
        }
        return ans;
    }
};