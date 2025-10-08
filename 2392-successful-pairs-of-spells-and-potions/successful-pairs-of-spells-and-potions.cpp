class Solution {
public:
    int bs(vector<int>& potions, long long success,int val){
        int n = potions.size();
        int i=0,j=n-1;
        int idx=-1;
        while(i<=j){
            int mid = i + (j-i)/2;
            if((long long)val*potions[mid]>=success){
                idx=mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        return idx==-1 ? 0 :  n-idx;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans(spells.size(),0);
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            ans[i]=bs(potions,success,spells[i]);
        }
        return ans;
    }
};