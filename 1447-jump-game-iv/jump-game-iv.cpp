class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++) mp[arr[i]].push_back(i);
        vector<bool>vis(n,false);
        queue<int>q;
        int steps=0;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int sz= q.size();
            while(sz--){
                int idx = q.front();
                if(idx==n-1) return steps;
                q.pop();
                if(idx-1>=0 && !vis[idx-1]){
                    q.push(idx-1);
                    vis[idx-1] = true;
                }
                if(idx+1<n && !vis[idx+1]){
                    q.push(idx+1);
                    vis[idx+1] = true;
                }
                for(int ele : mp[arr[idx]]){
                    if(!vis[ele]){
                        q.push(ele);
                        vis[ele] = true;
                    }
                }
                mp.erase(arr[idx]);
            }
            steps++;
        }
        return -1;
    }
};