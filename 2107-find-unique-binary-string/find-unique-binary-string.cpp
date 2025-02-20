class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans(n,' ');
        for(int i=0;i<n;i++){
            ans[i]=nums[i][i]=='1' ? '0' : '1';
        }
        return ans;
    }
};