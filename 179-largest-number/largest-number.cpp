class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>v;
        for(int num : nums){
            v.push_back(to_string(num));
        }
        auto myComp = [&v](string x, string y){
            return (x+y > y+x);
        };
        sort(v.begin(),v.end(),myComp);
        if(v[0]=="0") return "0";
        string ans="";
        for(auto ele : v) ans+=ele;
        return ans;
    }
};