class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int curr = 1, cnt = 0;
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i - 1]) {
                cnt += curr / 2;
                curr = 1;
            } else {
                curr++;
            }
        }
        cnt += curr / 2;
        
        return cnt == nums.size() / 2;
    }
};