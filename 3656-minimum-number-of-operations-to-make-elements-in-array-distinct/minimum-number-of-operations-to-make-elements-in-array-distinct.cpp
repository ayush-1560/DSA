class Solution {
public:
    bool check(vector<int>& nums,int idx){
        unordered_set<int>st;
        for(int i=idx;i<nums.size();i++){
            if(st.count(nums[i])) return false;
            st.insert(nums[i]);
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        for(int i=0;i<n;i+=3){
            if(check(nums,i)) return cnt;
            cnt++;
        }
        return cnt;
    }
};