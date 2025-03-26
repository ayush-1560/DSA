class Solution {
public:
    int findDiff(vector<int>&v,int idx1, int idx2){
        int ops1 = 0, ops2=0;
        for(int i=0;i<v.size();i++){
            ops1+=abs(v[idx1]-v[i]);
        }
        for(int i=0;i<v.size();i++){
            ops2+=abs(v[idx2]-v[i]);
        }
        if(ops1<ops2) return idx1;
        else return idx2;
    }
    int findAns(vector<int>&v,int idx,int x){
        int ans=0;
        for(int i=0;i<v.size();i++){
            int diff = abs(v[idx]-v[i]);
            if(diff%x!=0) return -1;
            while(diff!=0){
                diff-=x;
                ans++;
            }
        }
        return ans;
    }
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(),v.end());
        int s = v.size();
        int idx = s>=3 ? findDiff(v,s/2,s/2-1) : 0;
        return findAns(v,idx,x);
    }
};