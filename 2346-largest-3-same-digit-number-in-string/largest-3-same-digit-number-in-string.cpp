class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        vector<string>nums ={"000","111","222","333","444","555",
        "666","777","888","999"};
        for(int i=9;i>=0;i--){
            if(num.find(nums[i])!=string::npos) {
                ans=nums[i];
                break;
            }
        }
        return ans;
    }
};