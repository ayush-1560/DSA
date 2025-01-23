class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int maxi=INT_MIN;
        for(auto query : nums) maxi=max({maxi,query[0],query[1]});
        vector<int>line(maxi+2,0);
        for(auto query : nums){
            line[query[0]]++;
            line[query[1]+1]--;
        }
        int count=0;
        for(int i=1;i<line.size();i++) line[i]+=line[i-1];
        for(auto ele : line) if(ele) count++;
        return count;
    }
};