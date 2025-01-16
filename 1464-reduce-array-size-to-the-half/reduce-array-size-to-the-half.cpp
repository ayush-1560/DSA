class Solution {
public:
    typedef pair<int,int> P;
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto ele : arr) mp[ele]++;
        vector<int>freq;
        for(auto it : mp) freq.push_back(it.second);
        sort(freq.rbegin(),freq.rend());
        int removedCount =0,uniqueCount=0,half=arr.size()/2;
        for(auto num : freq){
            removedCount+=num;
            uniqueCount++;
            if(removedCount >=half) break;
        }
        return uniqueCount;
    }
};