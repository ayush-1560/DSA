class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int>v = nums;
        sort(v.begin(),v.end());
        int groupNum=0;
        unordered_map<int,int>groupNo;
        groupNo[v[0]]=groupNum;
        unordered_map<int,list<int>>groupToList;
        groupToList[groupNum].push_back(v[0]);
        for(int i=1;i<n;i++){
            if(abs(v[i]-v[i-1])>limit){
                groupNum++;
            }
            groupNo[v[i]]=groupNum;
            groupToList[groupNum].push_back(v[i]);
        }
        for(int i=0;i<n;i++){
            int num = nums[i];
            int group = groupNo[num];
            v[i] = *(groupToList[group].begin());
            groupToList[group].pop_front();
        }
        return v;
    }
};