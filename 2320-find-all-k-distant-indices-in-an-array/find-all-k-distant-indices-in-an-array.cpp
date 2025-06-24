class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>ans;
        int n = nums.size();
        for(int j=0;j<nums.size();j++){
            if(nums[j]==key){
                int start = max(0,j-k);
                int end = min(n-1,j+k);
                if(!ans.empty() && ans.back()>=start){
                    start=ans.back()+1;
                }
                for(int i=start;i<=end;i++) ans.push_back(i);
            }
        }
        return ans;
    }
};