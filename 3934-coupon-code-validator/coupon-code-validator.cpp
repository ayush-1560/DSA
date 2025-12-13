class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string,string>>v;
        unordered_set<string>st={"electronics", "grocery", "pharmacy", "restaurant"};
        vector<string>ans;
        for(int i=0;i<code.size();i++){
            bool flag = true;
            for(char ch : code[i]){
                if(!isalnum(ch) && ch!='_') flag = false;
            }
            if(isActive[i]==false) flag = false;
            if(!st.count(businessLine[i])) flag = false;
            if(flag) v.push_back({businessLine[i],code[i]});
        }
        sort(v.begin(),v.end());
        for(auto it : v) {
            if(!it.second.empty()) ans.push_back(it.second);
        }
        return ans;
    }
};