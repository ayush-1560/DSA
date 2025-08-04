class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int>mp;
        int maxLen = 0;
        int i =0 , j=0;
        while(j<n){
            mp[fruits[j]]++;
            if(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0) mp.erase(fruits[i]);
                i++;
            }
            maxLen = max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};