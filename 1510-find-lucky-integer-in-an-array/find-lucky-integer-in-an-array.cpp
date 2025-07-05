class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto ele : arr) mp[ele]++;
        int maxEle=-1;
        for(auto it : mp){
            if(it.second==it.first) maxEle = max(maxEle,it.first);
        }
        return maxEle;
    }
};