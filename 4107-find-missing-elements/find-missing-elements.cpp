class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        unordered_set<int>st(nums.begin(),nums.end());
        int minE = *min_element(nums.begin(),nums.end());
        int maxE = *max_element(nums.begin(),nums.end());
        
        for(int num=minE;num<=maxE;num++){
            if(!st.count(num)) ans.push_back(num);
        }

        return ans;
    }
};