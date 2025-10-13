class Solution {
public:
    bool isAnagram(string s1, string s2){
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return s1==s2;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        unordered_map<string,string>mp;
        int n = words.size();
        vector<string>ans;
        ans.push_back(words[0]);
        for(int i=1;i<n;i++){
            if(isAnagram(ans.back(),words[i])){
                continue;
            }
            else ans.push_back(words[i]);
        }
        return ans.size()==0 ? words : ans;
    }
};