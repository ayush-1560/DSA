class Solution {
public:
    int find(vector<int>& tops, vector<int>& bottoms,int val){
        int swapTops=0,swapBottoms=0;
        for(int i=0;i<tops.size();i++){
            if(tops[i]!=val && bottoms[i]!=val) return -1;
            else if(tops[i]!=val) swapTops++;
            else if(bottoms[i]!=val) swapBottoms++;
        }
        return min(swapTops,swapBottoms);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans =INT_MAX;
        for(int k=1;k<=6;k++){
            int steps = find(tops,bottoms,k);
            if(steps!=-1) ans = min(ans,steps);
        }
        return ans==INT_MAX ? -1 : ans;
    }
};