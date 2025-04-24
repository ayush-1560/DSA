class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        int n = nums.size();
        int i=0,j=0,count = 0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()==st.size()){
                count+=(n-j);
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return count;
    }
};