class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        map<string,int>mp;
        mp[event1[0]]++;
        mp[event1[1]+'1']--;
        mp[event2[0]]++;
        mp[event2[1]+'1']--;
        int sum=0;
        for(auto it : mp){
            sum+=it.second;
            if(sum>1) return true;
        }
        return false;
    }
};