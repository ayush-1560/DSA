class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int>ans;
        for(auto& ele : asteroids){
            while(!ans.empty() && ele<0 && ans.back()>0){
                int sum = ele + ans.back();
                if(sum<0) ans.pop_back();
                else if(sum>0) ele=0;
                else {
                    ans.pop_back();
                    ele=0;
                }
            }
            if(ele!=0) ans.push_back(ele);
        }
        return ans;
    }
};